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
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    range(i, n) cin >> ab[i].first;
    range(i, n) cin >> ab[i].second;
    sort(all(ab), [&](pair<int, int> &x, pair<int, int> &y) -> bool {
        return x.first - x.second < y.first - y.second;
    });
    auto ab2 = ab;
    sort(rall(ab2), [&](pair<int, int> &x, pair<int, int> &y) -> bool {
        return x.first - x.second < y.first - y.second;
    });
    int j=0;
    ll ans = 0;
    range(i, n) {
        while(j < n && ab2[j].second - ab2[j].first < ab[i].first - ab[i].second) {
           j++;
        }
        if (ab[i].first - ab[i].second > ab[i].second - ab[i].first) ans--;
        ans += j;
    }
    cout << ans / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}