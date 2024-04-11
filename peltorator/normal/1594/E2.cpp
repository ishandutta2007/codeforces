#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

ll mylg(ll v) {
    return 64 - __builtin_clzll(v);
}

ll get_first_leaf(ll v) {
    ll lg = __builtin_clzll(v) - 3;
    return (v << lg);
}

struct InType {
    ll v;
    int col;

    bool operator<(const InType& other) const {
        return make_pair(make_pair(get_first_leaf(v), v), col) < make_pair(make_pair(get_first_leaf(other.v), other.v), other.col);
    }
};

map<string, int> colors = {
    {"white", 0},
    {"blue", 1},
    {"orange", 2},
    {"yellow", 3},
    {"green", 4},
    {"red", 5},
};

std::istream& operator>>(std::istream& stream, InType& in) {
    ll v;
    string col;
    stream >> v >> col;
    in.v = v;
    in.col = colors[col];
    return stream;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    function<int(int, int, ll)> binpow = [&](int a, int b, ll MOD) -> int {
        if (b == 0) {
            return 1;
        }
        if (b & 1) {
            return 1LL * binpow(a, b - 1, MOD) * a % MOD;
        }
        return binpow(1LL * a * a % MOD, b >> 1, MOD);
    };
    const ll REALMOD = 1e9 + 7;
    auto defaultans = [&](int lvl) -> ll { 
        if (lvl == 0) {
            return 1;
        } else {
            return 1LL * binpow(16, binpow(2, lvl - 1, REALMOD - 1) - 1, REALMOD) % REALMOD;
        }
    };

    int n;
    cin >> n;
    set<InType> inp(istream_iterator<InType>(cin), {});
    function<vector<ll>(ll, int)> dfs = [&](ll v, int lvl) {
        auto lb = inp.lower_bound(InType{v, 0});
        if (lb != inp.end() && mylg(lb->v) >= mylg(v) && ((lb->v) >> (mylg(lb->v) - mylg(v))) == v) {
            int needcol = -1;
            if ((lb->v) == v) {
                needcol = lb->col;
            }
            if (lvl == 1) {
                if (needcol == -1) {
                    return vector<ll>(6, 1);
                } else {
                    vector<ll> ans2(6, 0);
                    ans2[needcol] = 1;
                    return ans2;
                }
            }
            vector<ll> ans(6, 0);
            auto ldp = dfs(2 * v, lvl - 1);
            auto rdp = dfs(2 * v + 1, lvl - 1); 
            ll l0 = (ldp[1] + ldp[2] + ldp[4] + ldp[5]) % REALMOD;
            ll l1 = (ldp[0] + ldp[2] + ldp[3] + ldp[5]) % REALMOD;
            ll l2 = (ldp[1] + ldp[0] + ldp[4] + ldp[3]) % REALMOD;
            ll l3 = l0;
            ll l4 = l1;
            ll l5 = l2;
            vector<ll> lefts = {l0, l1, l2, l3, l4, l5};

            ll r0 = (rdp[1] + rdp[2] + rdp[4] + rdp[5]) % REALMOD;
            ll r1 = (rdp[0] + rdp[2] + rdp[3] + rdp[5]) % REALMOD;
            ll r2 = (rdp[1] + rdp[0] + rdp[4] + rdp[3]) % REALMOD;
            ll r3 = r0;
            ll r4 = r1;
            ll r5 = r2;
            vector<ll> rights = {r0, r1, r2, r3, r4, r5};

            if (needcol != -1) {
                ans[needcol] = lefts[needcol] * rights[needcol] % REALMOD;
            } else {
                ans[0] = l0 * r0 % REALMOD;
                ans[1] = l1 * r1 % REALMOD;
                ans[2] = l2 * r2 % REALMOD;
                ans[3] = l3 * r3 % REALMOD;
                ans[4] = l4 * r4 % REALMOD;
                ans[5] = l5 * r5 % REALMOD;
            }
            return ans;
        } else {
            return vector<ll>(6, defaultans(lvl));
        }
    };
    auto ans = dfs(1, k);
    cout << accumulate(ans.begin(), ans.end(), 0LL, [](ll a, ll b) -> ll { return a + b; }) % REALMOD << endl;
}