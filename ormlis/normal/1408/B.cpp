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
const int maxN = 1e6 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    int cnt = 0;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    for(int i = 1; i < n; ++i) {
        if (a[i] > a[i-1]) cnt++;
    }
    // cnt <= m * (k-1)
    // m >= cnt / (k-1)
    if (k == 1) {
        if (cnt == 0) {
            cout << "1\n";
            return;
        }
        cout << "-1\n";
        return;
    }
    if (cnt == 0) {
        cout << "1\n";
        return;
    }
    int m = (cnt-1)/(k-1)+1;
    cout << m << "\n";
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