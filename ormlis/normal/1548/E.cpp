#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<pair<int, int>> solve(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> stk = {{-INFi, -INFi}};
    vector<pair<int, int>> result(n);
    range(i, n) {
        int mx = stk.back().second;
        while (!stk.empty() && stk.back().first >= a[i]) {
            stk.pop_back();
            mx = max(mx, stk.back().second);
        }
        stk.back().second = max(mx, a[i]);
        if (stk.size() == 1) mx = INFi;
        result[i] = {a[i], mx};
        stk.emplace_back(a[i], -INFi);
    }
    stk = {{-INFi, -INFi}};

    for (int i = n - 1; i >= 0; --i) {
        int mx = stk.back().second;
        while (!stk.empty() && stk.back().first > a[i]) {
            stk.pop_back();
            mx = max(mx, stk.back().second);
        }
        stk.back().second = max(mx, a[i]);
        if (stk.size() == 1) mx = INFi;
        result[i].second = min(result[i].second, mx);
        stk.emplace_back(a[i], -INFi);
    }

    return result;
}

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    int x; cin >> x;
    vector<int> a(n), b(m);
    range(i, n) cin >> a[i];
    range(i, m) cin >> b[i];
    auto p1 = solve(a), p2 = solve(b);
    sort(all(p1));
    sort(rall(p2));
    int j = 0;
    multiset<pair<int, int>> have;
    fenwick f;
    f.build(maxN);
    ll ans = 0;
    for(auto &[c, ct] : p2) {
        while(j < n && p1[j].first + c <= x) {
            have.insert({p1[j].second, p1[j].first});
            f.upd(p1[j].first, 1);
            j++;
        }
        while(!have.empty() && have.begin()->first + c <= x) {
            f.upd(have.begin()->second, -1);
            have.erase(have.begin());
        }
        if (ct == -INFi) continue;
        ans += f.get(x - ct + 1, maxN - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}