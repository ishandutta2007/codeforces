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
    ll sos = 0, sm = 0;
    cin >> n;
    vector<int> a(n), b(n);
    foru(i, 0, n)cin >> a[i], sos += (a[i] * a[i]), sm += a[i];
    foru(i, 0, n)cin >> b[i], sos += (b[i] * b[i]), sm += b[i];
    vector<bool> pos(10001, 0), prv = pos;
    pos[0] = 1;
    foru(i, 0, n) {
        prv = pos;
        fill(pos.begin(), pos.end(), false);
        for (int j = 0; j <= 10000; j++) {
            if (prv[j]) {
                if (j + a[i] <= 10000)pos[j + a[i]] = 1;
                if (j + b[i] <= 10000)pos[j + b[i]] = 1;
            }
        }
    }
    ll bst = 1e18;
    ll cur = (n - 2) * sos;
    for (ll j = 0; j <= 10000; j++) {
        if (!pos[j])continue;
        bst = min(bst, cur + j * j + (sm - j) * (sm - j));
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