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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> sr(k), st(n);
    foru(i, 0, k)cin >> sr[i], st[i + n - k] = sr[i];
    if (k == 1) {
        cout << "YES\n";
        return;
    }
    vector<ll> av;
    foru(j, 0, k - 1)av.push_back(sr[j + 1] - sr[j]);
    bool bad = 0;
    foru(j, 0, k - 2) {
        if (av[j] > av[j + 1])bad = 1;
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    ll fi = av[0], smprev = sr[0];
    ll hgh = fi * (n - k + 1);
    if (hgh < smprev) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}