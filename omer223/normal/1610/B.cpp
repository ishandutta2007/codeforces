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

const int sz = 5e5;
int n, a[sz];

void solve() {
    cin >> n;
    foru(i, 0, n)cin >> a[i];
    int idx = -1;
    foru(i, 0, n / 2) {
        if (a[i] != a[n - i - 1]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "YES\n";
        return;
    }
    int v[] = { a[idx], a[n - idx - 1] };
    foru(j, 0, 2) {
        vector<int> b;
        foru(i, 0, n) {
            if (a[i] != v[j])b.push_back(a[i]);
        }
        vector<int> c = b;
        reverse(c.begin(), c.end());
        if (b == c) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}