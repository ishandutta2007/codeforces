#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
int T, n, a[N];

void solve() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int mi = 2e9, x;
    rep(i, 2, n) if(a[i] - a[i - 1] < mi) mi = a[i] - a[i - 1], x = i;
    printf("%d ", a[x - 1]);
    rep(i, x + 1, n) printf("%d ", a[i]);
    rep(i, 1, x - 2) printf("%d ", a[i]);
    printf("%d\n", a[x]);
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    int T; for(cin >> T; T--;)
    solve();
}