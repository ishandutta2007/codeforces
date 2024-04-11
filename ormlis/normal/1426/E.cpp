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
#include <assert.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e7;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n; cin >> n;
    int a1, a2, a3, b1, b2, b3; cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
    int mn = 0;
    int op = 0;
    while (a1 > b1 + b3 || a2 > b2 + b1 || a3 > b3 + b2) {
        op++;
        if (a1 > b1 + b3) {
            int cnt = a1 - (b1+b3);
            mn += cnt;
            a1 -= cnt;
            b2 -= cnt;
        } else if (a2 > b2 + b1) {
            int cnt = a2 - (b2 + b1);
            mn += cnt;
            a2 -= cnt;
            b3 -= cnt;
        } else {
            int cnt = a3 - (b3 + b2);
            mn += cnt;
            a3 -= cnt;
            b1 -= cnt;
        }
    }
    cout << mn << " " << mx << "\n";
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