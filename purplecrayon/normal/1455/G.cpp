#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const ll INF = 1e18+10;

struct State {
    map<int, ll> mp;
    multiset<ll> values;
    ll delta = 0;

    void add_all(ll x) {
        delta += x;
    }
    void upd(int c, ll x) {
        if (mp.count(c))
            values.erase(values.find(mp[c]));

        mp[c] = x - delta;
        values.insert(x - delta);
    }
    ll qry(int c) {
        if (!mp.count(c)) return INF;
        return mp[c] + delta;
    }
    ll qry_min() {
        if (values.empty()) return INF;
        return *values.begin() + delta;
    }
};

int n, x, start[N];
State dp[N];

void merge_into(int c, int p) {
    int cur_start = start[c];
    if (!dp[p].mp.count(cur_start)) return;

    ll p_start = dp[p].qry(cur_start);
    ll c_start = dp[c].qry(cur_start);
    dp[c].add_all(p_start);
    if (sz(dp[c].mp) > sz(dp[p].mp)) {
        swap(dp[c].mp, dp[p].mp);
        swap(dp[c].values, dp[p].values);
        swap(dp[c].delta, dp[p].delta);
    }

    for (auto [k, v] : dp[c].mp) {
        v += dp[c].delta;
        dp[p].upd(k, min(dp[p].qry(k), v));
    }
    dp[p].upd(cur_start, p_start + c_start);
    dp[c].mp.clear();
}
void add(int c, ar<int, 2> a) {
    ll use = dp[c].qry_min();
    /*
    ll use = INF;
    for (auto& [k, v] : dp[c].mp) {
        use = min(use, v + dp[c].delta);
        // if (k != a[0])
        //    v += a[1];
    }
    */
    dp[c].add_all(a[1]);
    if (a[0] != x) dp[c].upd(a[0], use);
}
void solve() {
    cin >> n >> x;

    vector<int> st{n};
    dp[st.back()].upd(0, 0);

    memset(start, -1, sizeof(start));
    start[st.back()] = 0;

    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        if (t == "set") {
            int c, cost; cin >> c >> cost;
            add(st.back(), {c, cost});
        } else if (t == "if") {
            int c; cin >> c;
            st.push_back(i);
            start[i] = c;
            dp[i].upd(c, 0);
        } else if (t == "end") {
            merge_into(st.end()[-1], st.end()[-2]);
            st.pop_back();
        } else assert(false);
    }
    ll ans = dp[n].qry_min();

    /*
    ll ans = INF;
    for (auto& [_, v] : dp[n].mp) ans = min(ans, v + dp[n].delta);
    */
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}