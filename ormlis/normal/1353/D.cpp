#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> vs(n+1);
    vs[n].push_back({0, n - 1});
    vector<int> ans(n);
    int step = 1;
    for(int i = n; i > 0; --i) {
        sort(all(vs[i]));
        for(auto &p: vs[i]) {
            int mid = (p.second + p.first) / 2;
            ans[mid] = step++;
            vs[p.second - mid].push_back({mid + 1, p.second});
            vs[mid - p.first].push_back({p.first, mid - 1});
        }
    }
    range(i, n) cout << ans[i] << " ";
    cout << "\n";
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