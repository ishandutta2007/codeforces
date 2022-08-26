#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    multiset<int> s2;
    range(i, n * 2) {
        int a;
        cin >> a;
        s2.insert(a);
    }
    for(auto &j : s2) {
        int x = *s2.rbegin() + j;
        vector<pair<int, int>> ans;
        int X = x;
        bool bad = false;
        auto s = s2;
        while (!s.empty()) {
            auto it = s.end();
            it--;
            int y = *it;
            s.erase(it);
            if (s.find(x - y) == s.end()) {
                bad = true;
                break;
            }
            s.erase(s.find(x - y));
            ans.emplace_back(y, x - y);
            x = y;
        }
        if (bad) continue;
        cout << "YES\n";
        cout << X << '\n';
        for(auto &[a, b] : ans) cout << a << ' ' << b << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}