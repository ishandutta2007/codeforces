#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000 + 5;
const int P = 1000000007;

char s[MAX_N];

int main() {
    int T, x;
    scanf("%d", &T);
    while (T --) {
        scanf("%d%s", &x, s + 1);
        int n = strlen(s + 1);
        bool ov = x <= n;
        for (int l = 1; l <= x; l ++) {
            int m = n - l;
            int nn = n;
            for (int k = 2; k <= s[l] - '0'; k ++) {
                if (!ov) {
                    for (int i = 1; i <= n - l && nn + i <= x; i ++) {
                        s[nn + i] = s[l + i];
                    }
                }
                nn += m;
                if (nn >= x) {
                    ov = true;
                }
                nn = (nn % P + P) % P;
            }
            n = nn;
        }
        printf("%d\n", n);
    }
    return 0;
}