#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ciso646>
#include <cmath>
#include <complex>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop                                                                                                                                                   \
    char nyaa;                                                                                                                                                 \
    cin >> nyaa;
#define rep(i, n) for(int i = 0; i < n; i++)
#define per(i, n) for(int i = n - 1; i >= 0; i--)
#define Rep(i, sta, n) for(int i = sta; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define per1(i, n) for(int i = n; i >= 1; i--)
#define Rep1(i, sta, n) for(int i = sta; i <= n; i++)
#define all(v) (v).begin(), (v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);


using bt = array<ul, 16>;
bool operator<(const bt & a, const bt & b) {
    rep(i, 16)if (a[i] != b[i])return a[i] < b[i];
    return false;
}
bt operator^(bt a, const bt& b) {
    rep(i, 16)a[i] ^= b[i];
    return a;
}
map<bt, int> mp;
void solve() {
    int n, s, d; cin >> n >> s >> d;
    vector<bt> b(s);
    vector<bool> exi(n);
    rep(i, s) {
        fill(all(exi), false);
        int c; cin >> c;
        rep(j, c) {
            int x; cin >> x; x--;
            exi[x] = true;
        }
        rep(j, 16)rep(k, 64) {
            int loc = j * 64 + k; if (loc >= n)continue;
            if (exi[loc])b[i][j] ^= (ul)1 << k;
        }
    }
    vector<bt> qs(d);
    rep(i, d) {
        fill(all(exi), false);
        int c; cin >> c;
        rep(j, c) {
            int x; cin >> x; x--;
            exi[x] = true;
        }
        rep(j, 16)rep(k, 64) {
            int loc = j * 64 + k; if (loc >= n)continue;
            if (exi[loc])qs[i][j] ^= (ul)1 << k;
        }
    }
    int d1 = s / 3;
    int d2 = s - d1;
    map<bt, int> mp;
    
    int tmp = 0; bt cur = {};
    function<void(int)> dfs = [&](int loc) {
        if (loc == d2) {
            if (mp.find(cur) == mp.end())mp[cur] = tmp;
            else mp[cur] = min(mp[cur], tmp);
        }
        else {
            dfs(loc + 1);
            tmp++;
            cur = cur^b[d1 + loc];
            dfs(loc + 1);
            tmp--;
            cur = cur ^ b[d1 + loc];
        }
    }; dfs(0);
    vector<int> ans(d, mod);
    function<void(int)> dfs2 = [&](int loc) {
        if (loc == d1) {
            rep(i, d) {
                bt nw = cur ^ qs[i];
                if (mp.find(nw) != mp.end()) {
                    ans[i] = min(ans[i], mp[nw] + tmp);
                }
            }
        }
        else {
            dfs2(loc + 1);
            tmp++;
            cur = cur ^ b[loc];
            dfs2(loc + 1);
            tmp--;
            cur = cur ^ b[loc];
        }
    }; dfs2(0);
    rep(i, d) {
        if (ans[i] == mod)ans[i] = -1;
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
    // init_f();
    /// init();
    // expr();
    solve();
    return 0;
}