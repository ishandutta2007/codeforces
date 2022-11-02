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
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << "NO\n";
        return;
    }
    if (n & 1) {
        cout << "YES\n";
        foru(i, 0, n - 1)cout << 1 << ' ';
        cout << m - (n - 1) << '\n';
        return;
    }
    else {
        if (m & 1) {
            cout << "NO\n";
            return;
        }
        else {
            cout << "YES\n";
            foru(i, 0, n - 2)cout << 1 << ' ';
            cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
            return;
        }
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}