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
    int n, m, k;
    cin >> n >> m;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    cin >> k;
    vector<int> b(k);
    foru(i, 0, k)cin >> b[i];
    ll sa = 0, sb = 0;
    for (int x : a)sa += x;
    for (int y : b)sb += y;
    if (sa != sb) {
        cout << "No\n";
        return;
    }
    vector<pii> va, vb;
    for (int x : a) {
        int amt = 1;
        int y = x;
        while (y % m == 0) {
            amt *= m;
            y /= m;
        }
        if (!va.empty() && va.back().ff == y)va.back().ss += amt;
        else va.push_back({ y,amt });
    }
    for (int x : b) {
        int amt = 1;
        int y = x;
        while (y % m == 0) {
            amt *= m;
            y /= m;
        }
        if (!vb.empty() && vb.back().ff == y)vb.back().ss += amt;
        else vb.push_back({ y,amt });
    }
    if (va == vb)cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}