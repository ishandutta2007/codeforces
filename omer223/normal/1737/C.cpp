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
    int n, x, y;
    cin >> n;
    int r[3], c[3];
    foru(i, 0, 3)cin >> r[i] >> c[i];
    cin >> x >> y;
    map<int, int> rm, cm;
    foru(i, 0, 3)rm[r[i]]++, cm[c[i]]++;
    int cr = -1, cc = -1;
    for (auto ii : rm) {
        if (ii.ss == 2)cr = ii.ff;
    }
    for (auto ii : cm) {
        if (ii.ss == 2)cc = ii.ff;
    }
    if ((cr == 1 || cr == n) && (cc == 1 || cc == n)) {
        if (x == cr || y == cc)cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    if ((x & 1) == (cr & 1))cout << "YES\n";
    else if ((y & 1) == (cc & 1))cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}