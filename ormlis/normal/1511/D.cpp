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
#include <list>

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
const int maxN = 3e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    string res = "a";
    vector<vector<bool>> was(k, vector<bool> (k));
    vector<int> cnt(k, k);
    range(i, k * k) {
        int c = res.back() - 'a';
        int nxt = -1;
        for(int j = k - 1; j >= 0; --j) {
            if (was[c][j]) continue;
            if (nxt == -1 || cnt[j] > cnt[nxt]) nxt = j;
        }
        assert(nxt != -1);
        was[c][nxt] = true;
        res += char('a' + nxt);
    }
    while(res.size() < n) {
        res = res + res.substr(1);
    }
    range(i, n) cout << res[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}