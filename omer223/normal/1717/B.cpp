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
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--; c--;
    vector<vector<char>> ret(n, vector<char>(n, '.'));
    foru(i, 0, n) {
        int cr = (r + i) % n;
        int cc = (c + i) % n;
        foru(j, 0, n) {
            if (j % k == 0) {
                ret[(cr + j) % n][cc] = 'X';
            }
        }
    }
    foru(i, 0, n) {
        foru(j, 0, n)cout << ret[i][j];
        cout << '\n';
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}