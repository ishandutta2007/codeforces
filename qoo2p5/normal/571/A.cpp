#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

ll a, b, c, l;

ll solve(ll a, ll b, ll c, ll d) {
    if (a < b + c) {
        return 0;
    }

    d = min(d, a - b - c);
    return (d + 2) * (d + 1) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> a >> b >> c >> l;
    ll ans = (l + 3) * (l + 2) * (l + 1) / 6;

    for (int d = 0; d <= l; d++) {
        ans -= solve(a + d, b, c, l - d);
        ans -= solve(b + d, a, c, l - d);
        ans -= solve(c + d, a, b, l - d);
    }

    cout << ans << "\n";

    return 0;
}