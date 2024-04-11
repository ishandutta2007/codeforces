#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define db(v) cout << #v << " is " << v << endl
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

struct segtree {

};

int main() {
    lint n, k; cin >> n >> k;
    vector<pair<pll, lint>> wifi;
    for (lint i = 1; i <= n; i++) {
        char a; cin >> a;
        if (a == '1') {
            wifi.push_back({{max(1ll, i - k), min(n, i + k)}, i});
        }
    }
    sort(wifi.begin(), wifi.end());
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<lint> dp(n + 1, 0);
    lint res = 0, loc = 0;
    for (lint i = 1; i <= n; i++) {
        while (!pq.empty() && pq.top().se < i) pq.pop();
        while (loc < sz(wifi) && wifi[loc].fi.fi == i) {
            pq.push({dp[i - 1] + wifi[loc].se, wifi[loc].fi.se});
            loc++;
        }
        lint r = i + dp[i - 1];
        dp[i] = r;
        if (!pq.empty()) dp[i] = min(dp[i], pq.top().fi);
    }
    cout << dp[n] << "\n";
}