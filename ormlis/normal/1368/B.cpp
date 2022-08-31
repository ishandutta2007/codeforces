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
const int maxN = 5e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll k; cin >> k;
    ll current = 1;
    vector<ll> x(10, 1);
    int j = 0;
    while(current < k) {
        current /= x[j];
        x[j]++;
        current *= x[j];
        j = (j + 1) % 10;
    }
    string s = "codeforces";
    range(i, 10) {
        range(w, x[i]) cout << s[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}