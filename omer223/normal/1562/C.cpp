#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-poller-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back
#define CW 1
#define CCW 2
#define COLIN 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void solve() {
    string s;
    int n;
    cin >>n>> s;
    foru(i, 0, (n + 1) / 2) {
        int idx = n - i - 1;
        if (s[idx] == '0') {
            cout << 1 << ' ' << idx + 1 << ' ' << 1 << ' ' << idx << '\n';
            return;
        }
    }
    if (s[n / 2 - 1] == '1') {
        cout << n / 2 << ' ' << n - 1 << ' ' << n / 2 + 1 << ' ' << n << '\n';
    }
    else {
        cout << n / 2 << ' ' << n << ' ' << n / 2 + 1 << ' ' << n << '\n';
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}