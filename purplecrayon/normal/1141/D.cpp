#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int get(char c) {
    return c == '?' ? 26 : c - 'a';
}
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector<int> one[27], two[27];
    for (int i = 0; i < n; i++) {
        one[get(s[i])].push_back(i);
        two[get(t[i])].push_back(i);
    }

    vector<pair<int, int>> ans;
    auto add = [&](int a, int b) {
        if (!sz(one[a]) || !sz(two[b]))
            return false;

        int x = one[a].back(); one[a].pop_back();
        int y = two[b].back(); two[b].pop_back();

        ans.push_back({x, y});
        return true;
    };

    vector<pair<int, int>> ord;
    for (int i = 0; i < 26; i++) ord.push_back({i, i});
    for (int i = 0; i < 26; i++) ord.push_back({i, 26}), ord.push_back({26, i});
    ord.push_back({26, 26});

    for (auto [a, b] : ord) {
        while (add(a, b));
    }

    cout << sz(ans) << '\n';
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}