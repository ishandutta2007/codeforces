#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = __int128;

ll sum(int n) {
    return (ll)n * (n + 1) * (n * 2 + 1) / 6;
}
ll calc(int n, int m) {
    ll res = min(n, m);
    res *= res, res = res * (res + 1) / 2;
    if(n > m) {
        ll t = sum(n) - sum(m);
        return res + (t * 2 - (m - 1LL) * (n - m)) * m / 2;
    } else {
        ll t = sum(m - 1) - sum(n - 1);
        return res + (t * 2 + (n + 1LL) * (m - n)) * n / 2;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T, x1, y1, x2, y2;
    for(cin >> T; T--;) {
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = calc(x2, y2) - calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1);
        if(ans < 10000000000) printf("%lld\n", (int64_t)ans);
        else printf("...%010lld\n", int64_t(ans % 10000000000));
    }
}