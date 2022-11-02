#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int T, n, m, x, y;

void solve() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    printf("%d %d %d %d\n", 1, 1, n, m);
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    int T; for(cin >> T; T--;)
    solve();
}