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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    bool bad = false;
    range(i, n) if (a[i] != x) bad = true;
    if (!bad) {
        cout << "0\n";
        return;
    }
    ll sum = 0;
    range(i, n) sum += a[i];
    if (sum % n == 0 && sum / n == x) {
        cout << "1\n";
        return;
    }
    range(i, n) {
        if (a[i] == x) {
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";

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