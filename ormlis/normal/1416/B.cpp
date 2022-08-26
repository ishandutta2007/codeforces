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
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    range(i, n) cin >> a[i].first;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    range(i, n) a[i].second = i + 1;
    int s = 0;
    range(i, n) s += a[i].first;
    if (s % n != 0) {
        cout << "-1\n";
        return;
    }
    int need = s / n;
    sort(a.begin() + 1, a.end(), [] (const pair<int, int> &x, const pair<int, int> &y) {
       return (x.second - x.first % x.second) % x.second < (y.second - y.first % y.second) % y.second;
    });
    vector<ar<int, 3>> ans;
    for(int i = 1; i < n; ++i) {
        int w = (a[i].second - a[i].first % a[i].second) % a[i].second;
        ans.push_back({1, a[i].second, w});
        ans.push_back({a[i].second, 1, (a[i].first + w) / a[i].second});
    }
    for(int i = 1; i < n; ++i) {
        ans.push_back({1, i + 1, need});
    }
    cout << ans.size() << "\n";
    for(auto &p: ans) {
        range(i, 3) cout << p[i] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}