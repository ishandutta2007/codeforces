#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

using ld = long double;

int n, t; 
ld c, a[MAXN], ps[MAXN], rl[MAXN], approx[MAXN], tot = 0;

void rd(ld& x) {
    string s; cin >> s;
    x = stold(s);
}
void solve() {
    cin >> n >> t; rd(c);
    for (int i = 0; i < n; i++) rd(a[i]);

    auto get = [&](int l, int r) -> ld {
        return ps[r]-(l?ps[l-1]:ld(0));
    };

    for (int i = 0; i < n; i++) {
        ps[i] = a[i];
        if (i) ps[i] += ps[i-1];

        if (i >= t-1) rl[i] = get(i-t+1, i)/t;
        tot += a[i]/t, tot /= c;
        approx[i] = tot;
    }

    cout << fixed << setprecision(10);
    int m; cin >> m;
    while (m--) {
        int i; cin >> i, --i;
        cout << rl[i] << ' ' << approx[i] << ' ' << (abs<ld>(rl[i]-approx[i])/rl[i]) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}