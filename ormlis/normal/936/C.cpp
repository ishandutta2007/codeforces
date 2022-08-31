#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> sc(26), tc(26);
    vector<int> p(n);
    vector<int> pos(n);
    range(i, n) {
        sc[s[i] - 'a'].push_back(i);
        tc[t[i] - 'a'].push_back(i);
    }
    range(j, 26) {
        if (sc[j].size() != tc[j].size()) {
            cout << "-1\n";
            return;
        }
        range(i, (int) sc[j].size()) {
            p[sc[j][i]] = tc[j][i];
        }
    }
    vector<int> ops;
        range(i, n) pos[p[i]] = i;
    auto Do = [&](int len) {
        if (len == 0) return;
        reverse(all(p));
        reverse(p.begin() + len, p.end());
        ops.push_back(len);
        range(i, n) pos[p[i]] = i;
    };
    for (int i = 1; i < n; ++i) {
        Do(n - 1 - pos[i]);
        if (i == 1 || pos[1] < pos[0]) {
            Do(n - 1 - pos[0]);
            Do(i);
        } else {
            Do(n - pos[0]);
            Do(n - pos[i - 1]);
        }
    }
    if (p[0] != 0) Do(n);
    cout << ops.size() << '\n';
    for (auto &x : ops) cout << x << ' ';
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