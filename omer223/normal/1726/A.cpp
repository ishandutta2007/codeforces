#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define rep(i, k, n) foru(i, k, n)
#define sz(a) (int)(a.size())

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
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;



void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    foru(i, 0, n)cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    } 
    ll mx = 0;
    foru(i, 1, n)mx = max(mx, a[i]);
    ll a1 = mx - a[0];
    ll mn = 1e9;
    foru(i, 0, n - 1)mn = min(mn, a[i]);
    a1 = max(a1, a[n - 1] - mn);
    foru(i, 0, n - 1)a1 = max(a1, a[i] - a[i + 1]);
    cout << a1 << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}