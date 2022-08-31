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
    int n, le; cin >> n >> le;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n+1] = le;
    range(i, n) cin >> a[i + 1];
    n += 2;
    int left = 0;
    int right = n - 1;
    ld time1 = 0;
    ld time2 = 0;
    int v1 = 1, v2 = 1;
    while(left + 1 < right) {
        ld t1, t2;
        t1 = (ld)(a[left+1] - a[left])/(ld)v1;
        t2 = (ld)(a[right] - a[right-1])/(ld)v2;
        if (t1 + time1 < t2 + time2) {
            time1 += t1;
            left++;
            v1++;
        } else {
            time2 += t2;
            right--;
            v2++;
        }
    }
    ld al = (a[right] - a[left]);
    if (time1 < time2) {
        al -= (time2-time1) * v1;
        time1 = time2;
    } else {
        al -= (time1-time2) * v2;
    }
    time1 += al/(ld)(v1+v2);
    cout << time1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}