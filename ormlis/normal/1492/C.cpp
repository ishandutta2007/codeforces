#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 2e18 + 5;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;
    vector<int> positions;
    int j = 0;
    for(auto &c : t) {
        while(s[j] != c) j++;
        positions.push_back(j++);
    }
    reverse(all(t));
    j = s.size();
    j--;
    int ans = 0;
    for(auto &c : t) {
        while(s[j] != c) j--;
        positions.pop_back();
        if (!positions.empty()) {
            ans = max(ans, j - positions.back());
        }
        j--;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}