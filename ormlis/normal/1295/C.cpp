#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> co(26);
    for (int i = 0; i < s.size(); ++i) {
        char x = s[i];
        co[x - 'a'].push_back(i);
    }
    int ans = 1;
    int prev = -1;
    for (auto x: t) {
        if (co[x - 'a'].empty()) {
            cout << -1 << '\n';
            return;
        }
        auto k = upper_bound(all(co[x - 'a']), prev);
        if (k == co[x - 'a'].end()) {
            ans++;
            prev = co[x - 'a'][0];
        } else {
            prev = *k;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}