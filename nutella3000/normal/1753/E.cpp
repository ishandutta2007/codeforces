#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;
int n;
ll b, p, m;
vector<vector<ll>> plu{{1}}, pre;
vector<ll> mul{1};

ll solve(int count, vector<bool>& take) {
    int n = mul.size();
    ll prod = accumulate(all(mul), 1ll, multiplies<ll>());
    vector<ll> lmul(n, 1);
    for (int i = 1; i < n; ++i)
        lmul[i] = (take[i-1] ? 1ll : mul[i-1]) * lmul[i-1];

    ll res = 0;

    ll l = -1, r = 1e18 + 3;

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        int cnt = 0;
        ll nres = 0;
        for (int i = 0; i < n; ++i) {
            auto func = [&](ll val) { return val * prod / lmul[i] * (lmul[i] - 1); };
            int l2 = -1, r2 = plu[i].size();
            while (r2 - l2 > 1) {
                int mid2 = (l2 + r2) / 2;
                (func(plu[i][mid2]) >= mid ? l2 : r2) = mid2;
            }
            nres += func(pre[i][r2]);
            cnt += r2;
        }
        (cnt <= count ? r : l) = mid;
        if (cnt >= count) res = nres - (cnt - count) * mid;
    }

    for (int i = 0; i < n; ++i) {
        res += pre[i].back() * prod / lmul[i];
    }
    return res;
}

ll rec(int id, ll cost, vector<bool>& take) {
    if (cost > b) return 0;
    if (id == mul.size()) {
        return solve((b - cost) / p, take);
    }
    ll r1 = rec(id+1, cost, take);

    for (int i = 0; i < id; ++i) {
        if (mul[i] >= mul[id] && !take[i])
            return r1;
    }

    take[id] = true;
    ll r2 = rec(id+1, cost+m, take);
    take[id] = false;
    return max(r1, r2);
}

void run() {
    cin >> n >> b >> p >> m;
    for (int i = 0; i < n; ++i) {
        char c; int v;
        cin >> c >> v;
        if (c == '*') {
            if (v != 1) {
                mul.back() = v;
                mul.push_back(1);
                plu.push_back({});
            }
        } else {
            plu.back().push_back(v);
        }
    }
    for (auto& i : plu)
        sort(all(i), [](ll u, ll v) { return u > v; });
    for (auto& seg : plu) {
        pre.push_back({0});
        for (int i : seg) {
            pre.back().push_back(i + pre.back().back());
        }
    }
    vector<bool> take(mul.size());
    cout << rec(0, 0, take) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}