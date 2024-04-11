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



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    set<int> used;
    foru(i, 0, n)used.insert(i + 1);
    vector<int> ans(n, 1);
    ford(i, n - 1, 1) {
        if (a[i] < a[i - 1]) {
            int dif = a[i - 1] - a[i];
            int x = *used.lower_bound(dif);
            ans[x-1] = i + 1;
            used.erase(x);
        }
    }
    foru(i, 0, n)cout << ans[i] << ' ';
    cout << '\n';
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}