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
    int n; cin >> n;
    // ans = (n / k) * (k - 1) + max(n % k - 1, 0) - k + 1;
    if (n <= 3) {
        cout << "0" << endl;
        return;
    }
    pair<int, int> mx = {-1, -1};
    for(int k = 2; k <= n; ++k) {
        ll answer = (n / k) * (k - 1) + max(n % k - 1, 0) - (k - 1);
        mx = max(mx, {(int)answer, k});
    }
    int cntl = 0;
    vector<int> a(n);
    int k = mx.second;
    while(cntl < mx.first) {
        vector<int> v;
        range(i, n - 1) {
            if (a[i]) continue;
            if (i % k < k - 1) {
                a[i] = 1;
                cntl++;
                v.push_back(i);
            }
        }
        cout << v.size() << " ";
        for(auto &w: v) cout << w + 1 << " ";
        cout << endl;
        int x; cin >> x;
        if (x == -1) exit(0);
        int e = v.size();
        for(int i = x - 1; i < x + e - 1; ++i) {
            if (a[i%n]) {
                a[i%n] = 0;
                cntl--;
            }
        }
    }
    cout << "0" << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}