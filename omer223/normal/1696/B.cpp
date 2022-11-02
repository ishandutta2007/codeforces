#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

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
//https://www.youtube.com/watch?v=LA2c-ib2wsc


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    bool z = 1;
    for (int x : a) {
        if (x != 0)z = 0;
    }
    if (z) {
        cout << 0 << '\n';
        return;
    }
    int mnn = n, mxn = -1;
    foru(i, 0, n) {
        if (a[i] != 0) {
            mnn = min(i, mnn);
            mxn = max(i, mxn);
        }
    }
    bool good = 1;
    for (int j = mnn; j <= mxn; j++) {
        if (a[j] == 0)good = 0;
    }
    if (good)cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}