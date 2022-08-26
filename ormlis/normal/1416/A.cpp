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
    vector<vector<int>> a(n);
    vector<int> ans(n+1, INFi);
    range(i, n) {
        int x; cin >> x;
        x--;
        a[x].push_back(i);
    }
    range(i, n) {
        if (a[i].empty()) continue;
        int prev = -1;
        int mx = 0;
        for(auto &pos: a[i]) {
            mx = max(mx, pos - prev);
            prev = pos;
        }
        mx = max(mx, n - prev);
        ans[mx] = min(ans[mx], i);
    }
    int answer = INFi;
    for(int i = 1; i <= n; ++i) {
        answer = min(answer, ans[i]);
        if (answer == INFi) cout << "-1 ";
        else cout << answer + 1 << " ";
    }
    cout << "\n";
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