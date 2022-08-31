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
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 1e6 + 20;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n * m);
    rep(i, n) {
        rep(j, m) {
            int p = j * n + i;
            char x;
            cin >> x;
            if (x == '*') a[p] = 1;
        }
    }
    int s = accumulate(all(a), 0);
    int s2 = accumulate(a.begin(), a.begin() + s, 0);
    rep(_, q) {
        int x, y;
        cin >> x >> y;
        int p = (y - 1) * n + (x - 1);
        if (a[p]) {
            if (p < s) s2--;
            s--;
            a[p] ^= 1;
            if (a[s]) s2--;
        } else {
            if (a[s]) s2++;
            s++;
            a[p] ^= 1;
            if (p < s) s2++;
        }
        cout << s - s2 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}