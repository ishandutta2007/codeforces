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
const int maxN = 2e5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n, 0);
    ll ans = 0;
    range(i, n) {
        char x; cin >> x;
        if (x == 'W') {
            a[i] = 1;
            ans++;
            if (i && a[i-1]==1) ans++;
        }
    }
    vector<int> cur;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if (!a[i]) {
            cnt++;
            continue;
        }
        int j = i + 1;
        while(j < n && a[j] == 0) j++;
        if (j != i + 1 && j != n) cur.push_back(j-i-1);
    }
    sort(all(cur));
    for(auto &x: cur) {
        if (x > k) break;
        k -= x;
        ans += 2 * x + 1;
        cnt -= x;
    }
    if (k && cnt) {
        if (ans == 0) ans -= 1;
        ans += min(cnt, k) * 2;
    }
    ans = min(ans, 1ll * n * 2 - 1);
    cout << ans << "\n";
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