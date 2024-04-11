#include <bits/stdc++.h>

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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e6 + 30;
const int LG = 20;

map<int, int> dp;

int calc(int mask) {
    if (mask & 1) mask ^= 1;
    if (dp.count(mask)) return dp[mask];
    if (mask == 0) return dp[mask] = 0;
    vector<int> can;
    for(int i = 1; i <= 30; ++i) {
        if ((1 << i) > mask) break;
        can.push_back(calc((mask & ((1 << i) - 1)) | (mask >> i)));
    }
    sort(all(can));
    can.resize(unique(all(can)) - can.begin());
    rep(i, can.size()) {
        if (can[i] != i) return dp[mask] = i;
    }
    return dp[mask] = can.size();
}

void solve() {
    int n; cin >> n;
    map<int, int> have;
    rep(_, n) {
        int x; cin >> x;
        for(int p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                int c = 0;
                while(x % p == 0) {
                    c++;
                    x /= p;
                }
                have[p] |= (1 << c);
            }
        }
        if (x != 1) have[x] |= 2;
    }
    int res = 0;
    for(auto [x, y] : have) res ^= calc(y);
    cout << (res == 0 ? "Arpa\n" : "Mojtaba\n");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}