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
    vector<ll> cnts[2];
    foru(i, 0, 2)cnts[i].assign(26, 0);
    cnts[0][0] = cnts[1][0] = 1;
    int q;
    cin >> q;
    ll sm[2] = { 1,1 };
    while (q--) {
        string s;
        ll d, k;
        cin >> d >> k >> s;
        d--;
        for (char c : s)cnts[d][c - 'a'] += k;
        sm[d] += k * s.length();
        bool pos = 0;
        foru(i, 1, 26) {
            pos |= (cnts[1][i] != 0);
        }
        if (sm[0] == cnts[0][0]) {
            if (cnts[0][0] < cnts[1][0])pos = 1;
        }
        if (pos)cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}