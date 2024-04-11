#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

char s[100];

int C, R = 0x3f3f3f3f;

constexpr int maxn = 8;

int main() {
    int m, n;
    for (int i = 0; i < 8; ++i) {
        scanf("%s", s);
        int cnt = 0;
        for (char ch : s) if(ch == 'B') ++cnt;
        if (cnt == 8) ++C;
        R = std::min(cnt, R);
    }
    int result = R + C;
    if (C == 8) result = 8;
    printf("%d", result);
    return 0;
}