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
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int binpow(int a, int b) {
    if (b == 0) return 1;
    if ( b % 2) return (1ll * a * binpow(a, b - 1)) % md;
    int m = binpow(a, b / 2);
    return (1ll * m * m) % md;
}

void solve() {
    int n; cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; ++i) ans = (1ll * ans * i) % md;
    cout << ((ans - binpow(2, n-1)) % md + md) % md << "\n";
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