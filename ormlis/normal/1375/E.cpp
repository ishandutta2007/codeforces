#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 305;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<pair<int, int>> b;
    b = {{a[0], 0}};
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; ++i) {
        int start = i;
        for(int j = i - 1; j >= 0; --j) {
            if (b[j].first > a[i]) {
                ans.emplace_back(b[j].second, i);
                start = j;
            }
        }
        b.insert(b.begin() + start, {a[i], i});
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(auto &p: ans) cout << p.first + 1 << " " << p.second + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}