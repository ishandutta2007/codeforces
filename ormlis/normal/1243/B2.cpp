#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e3;
const int md = 998244353;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        for(int j = i + 1; j < n; ++j) {
            if (t[j] == t[i]) {
                swap(s[i], t[j]);
                ans.push_back({i + 1, j + 1});
                break;
            }
        }
        if (s[i] == t[i]) continue;
        for(int j = i + 1; j < n; ++j) {
            if (s[j] == t[i]) {
                swap(s[j], t[j]);
                ans.emplace_back(j + 1, j + 1);
                swap(s[i], t[j]);
                ans.emplace_back(i + 1, j + 1);
                break;
            }
        }
        if (s[i] != t[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    cout << ans.size() << '\n';
    for(auto &[i, j] : ans) cout << i << ' ' << j << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}