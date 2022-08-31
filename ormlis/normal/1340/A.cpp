#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    range(i, n) cin >> p[i];
    vector<int> pos(n);
    range(i, n) {
        p[i]--;
        pos[p[i]] = i;
    }
    set<pair<int, int>> s;
    range(i, n) s.insert({i, i});
    multiset<int> lens;
    range(i, n) lens.insert(1);
    range(i, n) {
        int w = pos[i];
        auto it = prev(s.upper_bound({w, w}));
        auto pa = *it;
        int le = pa.second - pa.first + 1;
        lens.erase(lens.find(le));
        s.erase(it);
        if (!lens.empty() && le < (*lens.rbegin())) {
            cout << "No\n";
            return;
        }
        auto it2 = s.upper_bound({w, w});
        if (it2 != s.end()) {
            pa.second = it2->second;
            lens.erase(lens.find(it2->second - it2->first + 1));
            s.erase(it2);
            s.insert(pa);
            lens.insert(pa.second - pa.first + 1);
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}