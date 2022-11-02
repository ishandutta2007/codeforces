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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


int foo(string s) {
    int n = s.length();
    int tot = 0;
    foru(i, 0, n - 1) {
        if (s[i] == '1')tot += 10;
        if (s[i + 1] == '1')tot += 1;
    }
    return tot;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int lz = -1, rz = -1;
    foru(i, 0, n) {
        if (s[i] == '1') {
            lz = i;
            break;
        }
    }
    ford(i, n - 1, 0) {
        if (s[i] == '1') {
            rz = i;
            break;
        }
    }
    if (lz == -1) {
        cout << 0 << '\n';
        return;
    }
    else if (lz == rz) {
        int rop = n - 1 - rz, lop = lz;
        if (k >= rop) {
            swap(s[rz], s[n - 1]);
        }
        else if (k >= lop) {
            swap(s[lz], s[0]);
        }
    }
    else {
        int rop = n - 1 - rz;
        if (k >= rop) {
            swap(s[rz], s[n - 1]);
            k -= rop;
        }
        int lop = lz;
        if (k >= lop) {
            swap(s[lz], s[0]);
        }
    }
    cout << foo(s) << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}