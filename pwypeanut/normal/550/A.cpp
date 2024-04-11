#include <bits/stdc++.h>
using namespace std;

char S[100005];

int main() {
    scanf("%s", &S);
    char *find1, *find2;
    // AB then BA
    find1 = strstr(S, "AB");
    if (find1 == (void*)0) {
        goto next;
    }
    find2 = strstr(find1 + 2, "BA");
    if (find2 == (void*)0) {
        goto next;
    }
    printf("YES\n");
    return 0;
    next:
        find1 = strstr(S, "BA");
        if (find1 == (void*)0) {
            printf("NO\n");
            return 0;
        }
        find2 = strstr(find1 + 2, "AB");
        if (find2 == (void*)0) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
}