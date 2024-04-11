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
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void solve() {
    int n, cnt = 0, idx=2;
    cin >> n;
    bool f = 1;
    while (n--) {
        int x;
        cin >> x;
        bool found = 0;
        foru(r, 0, cnt + 1) {
            if (x % (idx - r)) {
                found = 1;
                break;
            }
        }
        f &= found;
        cnt += found;
        idx++;
    }
    cout << (f ? "YES\n" : "NO\n");
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}