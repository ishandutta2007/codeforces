#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n, le, v1, v2;
    cin >> n >> le >> v1 >> v2;
    double x = le - (double) le * v1 / (v1 + v2);
    vector<pair<double, int>> a;
    int b = 0;
    range(i, n) {
        int c;
        cin >> c;
        if (c  < x) {
            b++;
            a.emplace_back(c-x + 2 * le, -1);
        } else {
            a.emplace_back(c-x, -1);
        }
        a.emplace_back(c, 1);
    }
    sort(all(a));
    vector<double> ans(n+1, 0);
    a.emplace_back(2 * le, 2);
    range(i,n * 2 + 1) {
        if (i && a[i].first != a[i-1].first) {
            ans[b] += a[i].first - a[i-1].first;
        }
        if (!i) ans[b] += a[i].first;
        b -= a[i].second;
    }
    cout << setprecision(15) << fixed;
    range(i, n + 1) {
        cout << ans[i] / (2 * le) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}