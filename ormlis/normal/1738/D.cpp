#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 100 + 10;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vvi g(n + 1);
    bool wtf = false;
    rep(i, n) {
        int x;
        cin >> x;
        if (x == 0) {
            x = n + 1;
            wtf = true;
        }
        x--;
        g[x].push_back(i);
    }
    int start = n;
    vvi s(2);
    vi a;
    int cur = 0;
    while (start != -1) {
        cur ^= 1;
        int nxt = -1;
        for (auto x: g[start]) {
            s[cur].push_back(x);
            if (!g[x].empty()) {
                assert(nxt == -1);
                nxt = x;
            } else {
                a.push_back(x);
            }
        }
        if (nxt != -1) a.push_back(nxt);
        start = nxt;
    }
    if (s[0].size() < s[1].size()) swap(s[0], s[1]);
    int k;
    if (s[0].size() == n) {
        if (wtf) k = 0;
        else k = n;
    } else if (s[0].back() < s[1].back()) {
        k = s[0].size();
    } else {
        k = s[1].size();
    }
    cout << k << '\n';
    for(auto x : a) cout << x + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}