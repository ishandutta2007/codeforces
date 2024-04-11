#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    bool good = 0;
    ll sm = 0, o = 0;
    foru(i, 1, n - 1) {
        if (a[i] % 2 == 0) {
            good = 1;
        }
        else o++;
        sm += a[i];
    }
    if (!good) {
        foru(i, 1, n - 1) {
            if (a[i] >= 3 && n - 2 > 1)good = 1;
        }
        if (!good) {
            cout << -1 << '\n';
        }
        else {
            o--;
            sm--;
            cout << o + (sm - o) / 2 + 1 << '\n';
        }
    }
    else cout << o + (sm - o) / 2 << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}