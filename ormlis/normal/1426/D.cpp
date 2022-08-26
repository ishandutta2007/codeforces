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
    vector<pair<int, int>> lr;
    map<ll, int> mp;
    mp[0] = 0;
    ll s = 0;
    range(i, n) {
        ll a; cin >> a;
        s += a;
        if (mp.count(s)) {
            lr.emplace_back(mp[s], i);
        }
        mp[s] = i+1;
    }
    sort(all(lr), [] (const pair<int, int> &x, const pair<int, int> &y) {
        return x.second < y.second;
    });
    int last = -1;
    int cnt = 0;
    for(auto &[l, r] : lr) {
        if (l >= last) {
            last = r;
            cnt++;
        }
    }
    cout << cnt << "\n";
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