#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n,  x, y; cin >> n >> x >> y;
    int z = y - x;
    pair<int, int> ans = {INFi, INFi};
    for(int i = 1; i <= z; ++i) {
        if (z % i != 0) continue;
        if (z / i + 1 > n) continue;
        int cnt = (y - 1) / i + 1;
        if (cnt >= n) ans = {y, i};
        else ans = min(ans, {y + (n - cnt) * i, i});
    }
    range(i, n) cout << ans.first - ans.second * i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}