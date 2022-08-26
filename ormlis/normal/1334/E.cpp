#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int fact[maxN];

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

ll powb(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return a * powb(a, b - 1);
    ll mid = powb(a, b / 2);
    return mid * mid;
}

int rev(int a) {
    return binpow(a, md - 2);
}
void init() {
    fact[0] = 1;
    for(int i = 1; i < maxN; ++i) fact[i] = mul(fact[i-1], i);
}

void solve() {
    ll D; cin >> D;
    init();
    map<ll, vector<pair<ll, int>>> mp;

    auto Solve = [&] (ll v) {
        if (mp.count(v)) return;
        ll k = v;
        vector<pair<ll, int>> g;
        for(ll i = 2; i * i <= v; ++i) {
            if (v % i == 0) {
                g.emplace_back(i, 0);
                while(v % i == 0) {
                    g.back().second++;
                    v /= i;
                }
            }
        }
        if (v != 1) g.emplace_back(v, 1);
        mp[k] = g;
    };

    auto Cnt = [&] (ll v, ll w) {
        int ans = 1;
        int f = 0;
        for(int i = 0, j = 0; i < (mp[v].size()); ++i) {
            if (j == mp[w].size() || mp[v][i].first != mp[w][j].first) {
                f += mp[v][i].second;
                ans = mul(ans, rev(fact[mp[v][i].second]));
            } else {
                f += mp[v][i].second - mp[w][j].second;
                ans = mul(ans, rev(fact[mp[v][i].second - mp[w][j].second]));
                j++;
            }
        }
        return mul(ans, fact[f]);
    };

    auto chk_path = [&] (ll v) {
        ll ans = 1;
        for(auto &x: mp[v]) {
            ans *= x.second + 1;
        }
        return ans - 1;
    };

    auto get_path = [&] (ll v, ll w) {
        return chk_path(v) - chk_path(w);
    };

    int q; cin >> q;
    range(_, q) {
        ll v, u; cin >> v >> u;
        ll w = __gcd(u, v);
        Solve(v);
        Solve(u);
        Solve(w);
        cout << mul(Cnt(v, w), Cnt(u, w)) << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}