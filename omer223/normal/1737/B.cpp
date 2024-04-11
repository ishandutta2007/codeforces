#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

ll floorsq(ll x) {
    ll sq = sqrt(x), fl = sq;
    for (int del = -2; del <= 2; del++) {
        ll n = sq + del;
        if (n <= 0)continue;
        if (n * n <= x)fl = n;
    }
    return fl;
}

ll foo(ll x) {
    if (x <= 4)return x;
    ll fl = floorsq(x);
    ll tot = 3 * (fl - 1);
    ll y = fl * fl;
    while (y <= x) {
        tot++;
        y += fl;
    }
    return tot;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << foo(r) - foo(l - 1) << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}