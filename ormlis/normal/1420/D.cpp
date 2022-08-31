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
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int fact[maxN];
int invfact[maxN];

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

void init() {
    fact[0] = 1;
    for(int i = 1; i < maxN; ++i) fact[i] = mul(fact[i-1], i);
}

int C(int n, int k) {
    if (k > n) return 0;
    return mul(fact[n], mul(rev(fact[k]), rev(fact[n-k])));
}

void solve() {
    init();
    int n,k; cin >> n >> k;
    int ans = 0;
    vector<pair<int, int>> arr;
    range(i, n) {
        int l, r; cin >> l >> r;
        arr.emplace_back(l, - 1);
        arr.emplace_back(r, 1);
    }
    sort(all(arr));
    int bal = 0;
    for(auto &p: arr) {
        if (p.second == -1) {
            ans = add(ans, C(bal, k - 1));
        }
        bal -= p.second;
    }
    cout << ans << "\n";
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