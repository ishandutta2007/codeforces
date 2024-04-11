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
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> pref(n, vector<int> (n));
    range(i, n) cin >> a[i];
    range(i, n) a[i]--;
    pref[0][a[0]]++;
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i-1];
        pref[i][a[i]]++;
    }
    auto cnt = [&] (int a, int l, int r) {
        if (l == n) return 0;
        if (r == -1) return 0;
        if (l == 0) return pref[r][a];
        return pref[r][a] - pref[l-1][a];
    };

    ll ans = 0;
    range(k, n) {
        range(j, k) {
            ans += 1ll * cnt(a[k], 0, j-1) * cnt(a[j], k + 1, n-1);
        }
    }
    cout << ans << "\n";
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