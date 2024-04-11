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
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

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
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    range(i, n) cin >> a[i];
    vector<pair<int, int>> ans;
    vector<pair<int, int>> stk1;
    vector<int> stk2;
    int cur = n;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ans.emplace_back(cur, i + 1);
            stk1.emplace_back(i + 1, cur);
            cur -= 1;
            continue;
        }
        if (a[i] == 2) {
            if (stk1.empty()) {
                cout << "-1\n";
                return;
            }
            ans.emplace_back(stk1.back().second, i + 1);
            cur -= 1;
            stk1.pop_back();
            stk2.push_back(i + 1);
            continue;
        }
        ans.emplace_back(cur, i + 1);
        if (!stk2.empty()) {
            ans.emplace_back(cur, stk2.back());
            stk2.pop_back();
        } else if (!stk1.empty()) {
            ans.emplace_back(cur, stk1.back().first);
            stk1.pop_back();
        } else {
            cout << "-1\n";
            return;
        }
        stk2.push_back(i + 1);
        cur -= 1;
    }
    cout << ans.size() << "\n";
    for (auto &[i, j] : ans) cout << i << " " << j << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}