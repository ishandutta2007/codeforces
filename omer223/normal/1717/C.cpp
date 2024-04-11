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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b = a;
    foru(i, 0, n)cin >> a[i];
    foru(i, 0, n)cin >> b[i];
    bool bad = 0;
    foru(i, 0, n) {
        if (a[i] > b[i])bad = 1;
        if (b[i] > max(a[i], b[(i + 1) % n] + 1))bad = 1;
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
        return;
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}