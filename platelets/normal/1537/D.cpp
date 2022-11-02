#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int T, n, f[10000];

void solve() {
    scanf("%d", &n);
    int t = __builtin_ctz(n);
    puts((n <= 10 ? f[n] : n & (n - 1) ? n % 2 == 0 : ~t & 1) ? "Alice" : "Bob");
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    rep(i, 2, 10) for(int j = 2; j * j <= i; j++) if(i % j == 0)
        f[i] |= !f[i - j] | !f[i - i / j];
    int T; for(cin >> T; T--;)
    solve();
}