#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

const int sz = 2e5 + 5;
const ll mod = 998244353;

void imult(ll & lhs, const ll & rhs) {
    lhs = (lhs * rhs) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = (lhs + rhs) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return (lhs * rhs) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return (lhs + rhs) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}


const int N = sz;
vector<int> lp(N + 1);
vector<int> pr;
ll invs[N + 1];


void sieve() {
    for (int i = 1; i <= N; i++)invs[i] = inv(i);
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

vector<pair<int, pii>> adj[sz];
ll dp[sz];

map<int, int>* dfs(int src, int prv) {
    bool leaf = 1;
    vector<map<int, int>*> v;
    for (auto ii : adj[src]) {
        int dst = ii.ff, x = ii.ss.ff, y = ii.ss.ss;
        if (dst == prv)continue;
        leaf = 0;
        map<int, int>* ans = dfs(dst, src);
        int yy = y;
        while (yy != 1) {
            (*ans)[lp[yy]]++;
            yy /= lp[yy];
        }
        int xx = x;
        while (xx != 1) {
            if (ans->count(lp[xx])) {
                (*ans)[lp[xx]]--;
                if ((*ans)[lp[xx]] == 0)ans->erase(lp[xx]);
            }
            xx /= lp[xx];
        }
        v.push_back(ans);
    }
    if (leaf) {
        map<int, int>* ret = new map<int, int>();
        return ret;
    }
    else {
        int mxs = -1;
        int mxidx = -1;
        int m = v.size();
        foru(i, 0, m) {
            if ((int)v[i]->size() > mxs) {
                mxs = v[i]->size();
                mxidx = i;
            }
        }
        foru(i, 0, m) {
            if (i == mxidx)continue;
            for (auto ii : *v[i]) {
                (*v[mxidx])[ii.ff] = max((*v[mxidx])[ii.ff], ii.ss);
            }
        }
        return v[mxidx];
    }
}

void dfs2(int src, int prv) {
    for (auto ii : adj[src]) {
        int dst = ii.ff, x = ii.ss.ff, y = ii.ss.ss;
        if (dst == prv)continue;
        dp[dst] = mult(dp[src], mult(x, invs[y]));
        dfs2(dst, src);
    }
}

void reset(int n) {
    foru(i, 0, n)adj[i].clear(), dp[i] = 1;
}

void solve() {
    int n;
    cin >> n;
    reset(n);
    foru(_, 0, n-1) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        int g = gcd(x, y);
        x /= g;
        y /= g;
        adj[--i].push_back({ --j,{y,x} });
        adj[j].push_back({ i,{x,y} });
    }
    map<int, int>* mem = dfs(0, -1);
    ll x = 1;
    for (auto ii : *mem)imult(x, bpw(ii.ff, ii.ss));
    dp[0] = x;
    dfs2(0, -1);
    ll ans = 0;
    foru(i, 0, n)iadd(ans, dp[i]);
    cout << ans << '\n';
}



int main() {
    fast;
    sieve();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}