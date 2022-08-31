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

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}



void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    range(i, n) cin >> k[i];
    sort(rall(k));
    if (p == 1) {
        cout << n % 2 << "\n";
        return;
    }
    map<int, int> mp1, mp2;
    int c = -1;
    int ans1 = 0, ans2 = 0;
    function<void(int)> add1 = [&](int x) {
        mp1[x] += 1;
        if (mp1[x] == p) {
            mp1[x] = 0;
            add1(x + 1);
            return;
        }
        if (x == c) {
            c = -1;
        }
    };
    function<void(int)> add2 = [&](int x) {
        mp2[x] += 1;
        if (mp2[x] == p) {
            mp2[x] = 0;
            add2(x + 1);
            return;
        }
        c = x;
    };
    range(i, n) {
        if (c == -1) {
            add2(k[i]);
            ans2 = add(ans2, binpow(p, k[i]));
        } else {
            add1(k[i]);
            ans1 = add(ans1, binpow(p, k[i]));
        }
    }
    cout << sub(ans2, ans1) << "\n";
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