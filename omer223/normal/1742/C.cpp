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
    vector<string> s(8);
    foru(i, 0, 8)cin >> s[i];
    int ret = 2;
    foru(i, 0, 8) {
        if (s[i][0] != 'R')continue;
        bool bad = 0;
        foru(j, 1, 8) {
            if (s[i][j] != s[i][j - 1]) {
                bad = 1;
                break;
            }
        }
        if (!bad) {
            ret = 1;
            break;
        }
    }
    if (ret == 1)cout << "R\n";
    else cout << "B\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}