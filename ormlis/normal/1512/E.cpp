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

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, l, r, s; cin >> n >> l >> r >> s;
    vector<int> ans(n);
    l--;
    int kek = (r - l) * (r - l + 1) / 2;
    if (s < kek) {
        cout << "-1\n";
        return;
    }
    s -= kek;
    int mx = n;
    set<int> used;
    range(i, n) used.insert(i + 1);
    for(int i = l; i < r; ++i) {
        ans[i] = r - i;
        int d = min(s, mx - ans[i]);
        ans[i] += d;
        s -= d;
        mx--;
        used.erase(ans[i]);
    }
    if (s) {
        cout << "-1\n";
        return;
    }
    range(i, n) {
        if (ans[i] == 0) {
            ans[i] = *used.begin();
            used.erase(used.begin());
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}