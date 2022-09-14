#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 300002, MOD = 998244353;
ll f[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % MOD;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
        b[i] = a[i].second;
    }
    sort(all(a));
    sort(all(b));
    ll c1 = 1, c2 = 1, c3 = 1, l1 = 1, l2 = 1, l3 = 1;
    for (int i = 1; i <= n; i++) {
        if (i == n || a[i] != a[i - 1]) {
            c1 = c1 * f[l1] % MOD;
            l1 = 1;
        }
        else
            l1++;
        if (i == n || a[i].first != a[i - 1].first) {
            c2 = c2 * f[l2] % MOD;
            l2 = 1;
        }
        else
            l2++;
        if (i == n || b[i] != b[i - 1]) {
            c3 = c3 * f[l3] % MOD;
            l3 = 1;
        }
        else
            l3++;
        if (i < n && a[i].second < a[i - 1].second)
            c1 = 0;
    }
    cout << (f[n] - c2 - c3 + c1 + MOD * 2)  % MOD;
}