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
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    ll sm = 0;
    for (int x : a)sm += x;
    if (sm != 0) {
        cout << "No\n";
        return;
    }
    bool bad = 0;
    ll crsm = 0;
    bool reached = 0;
    for (int x : a) {
        if (reached && x != 0)bad = 1;
        crsm += x;
        if (crsm == 0) {
            reached = 1;
        }
        else if (crsm < 0)bad = 1;
    }
    if (bad)cout << "No\n";
    else cout << "Yes\n";
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}