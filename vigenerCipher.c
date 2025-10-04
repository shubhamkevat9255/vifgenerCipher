#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char *text, char *key) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[j % keyLen]) - 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

void vigenereDecrypt(char *text, char *key) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[j % keyLen]) - 'a';
            text[i] = (text[i] - base - shift + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    char msg[100], key[20];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = 0; // remove newline

    printf("Enter keyword: ");
    scanf("%s", key);

    vigenereEncrypt(msg, key);
    printf("Encrypted: %s\n", msg);

    vigenereDecrypt(msg, key);
    printf("Decrypted: %s\n", msg);

    return 0;
}
