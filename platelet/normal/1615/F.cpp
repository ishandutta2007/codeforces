#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2000 + 5, P = 1e9 + 7;

int T, n, C[N * 2][N * 2], a1[N], a2[N], b1[N], b2[N];
char s[N], t[N];

ll calc(int la, int ra, int lb, int rb) {
    int n = a2[ra] + b2[rb] - a2[la] - b2[lb];
    int m = b2[rb] - b2[lb] - a1[ra] + a1[la] + b1[rb] - b1[lb];
    return 0 <= m && m <= n ? C[n][m] : 0;
}
int main() {
    int T;
    for(cin >> T; T--;) {
        scanf("%d%s%s", &n, s + 1, t + 1);
        rep(i, 0, n << 1) rep(j, 0, i) C[i][j] = j ? (C[i - 1][j - 1] + C[i - 1][j]) % P : 1;
        rep(i, 1, n) {
            if(i % 2 && s[i] < 50) s[i] ^= 1;
            if(i % 2 && t[i] < 50) t[i] ^= 1;
            a1[i] = a1[i - 1] + (s[i] == '1');
            a2[i] = a2[i - 1] + (s[i] == '?');
            b1[i] = b1[i - 1] + (t[i] == '1');
            b2[i] = b2[i - 1] + (t[i] == '?');
        }
        int ans = 0;
        rep(i, 1, n) rep(j, 1, n) if(s[i] != '0' && t[j] != '0')
            ans = (ans + abs(i - j) * calc(0, i - 1, 0, j - 1) % P * calc(i, n, j, n)) % P;
        printf("%d\n", ans);
    }
}