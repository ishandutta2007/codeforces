#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
char s[N], t[N];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') {
            pos = i;
            break;
        }
    }
    if (n - 1 > m) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i < pos; i++) {
        if (s[i] != t[i]) {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = n, j = m; i > pos; i--, j--) {
        if (s[i] != t[j]) {
            printf("NO\n");
          return 0;
        }
    }
    printf("YES\n");
    return 0;
}