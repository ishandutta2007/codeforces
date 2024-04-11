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



int n;
const int sz = 2e5 + 5;
ll fen[sz], a[sz], b[sz];

bool ok(int x) {
    x--;
    int reach = 0;
    foru(i, 0, n) {
        if (a[i] >= reach && b[i] >= x - reach)reach++;
        if (reach == x + 1)return 1;
    }
    return 0;
}

void solve() {
	cin >> n;
	foru(i, 0, n)cin >> b[i] >> a[i];
    int l = 1, r = n, mid, bst = 1;
    while (l <= r) {
        mid = (l + r + 1) / 2;
        if (ok(mid)) {
            bst = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}