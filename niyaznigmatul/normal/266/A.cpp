#include <cstdio>
#include <algorithm>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        sg = 1;
        c = getchar();
    }   
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;
}

char s[1123];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && s[i] == s[j]) ++j;
        ans += j - i - 1;
        i = j;
    }
    printf("%d\n", ans);
}