#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vi ans(n);
    ans[n - 1] = 0;
    for(auto to : {1, n}) {
        for(int k = 1; k <= n; ++k) {
            cout << "? ";
            rep(_, n - 1) cout << k << ' ';
            cout << to << endl;
            int x; cin >> x;
            if (x == 0) continue;
            x--;
            // a[n - 1] + to == a[x] + k
            // a[x] == to - k
            ans[x] = to - k;
        }
    }
    int mn = *min_element(all(ans));
    rep(i, n) ans[i] = (ans[i] - mn) + 1;
    cout << "! ";
    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}