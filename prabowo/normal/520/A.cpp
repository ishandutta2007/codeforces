#include <cstdio>

int n;
char s[102];
bool alfa[102];

int main () {
    scanf("%d %s", &n, s);

    for (int i=0; i<n; i++) {
        if (s[i] >= 'a') alfa[s[i]-'a'] |= 1;
        else alfa[s[i]-'A'] |= 1;
    }

    bool ok = 1;
    for (int i=0; i<26; i++) ok &= alfa[i];

    if (ok) puts("YES");
    else puts("NO");

    return 0;
}