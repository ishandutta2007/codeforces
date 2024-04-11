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
    int cnt = accumulate(all(a), 0);
    int prev = -1;
    int h = 0;
    while(cnt) {
        int mx = -1;
        range(i, n) {
            if (i == prev) continue;
            if (!a[i]) continue;
            if (mx == -1 || a[mx] < a[i]) mx = i;
        }
        if (mx == -1) {
            break;
        }
        a[mx]--;
        cnt--;
        prev = mx;
        h++;
    }
    if (h % 2) {
        cout << "T\n";
    } else {
        cout << "HL\n";
    }
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