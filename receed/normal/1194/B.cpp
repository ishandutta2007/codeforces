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

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        vector<string> a(n);
        vector<int> b(n), c(m);
        rep(i, n) {
            cin >> a[i];
            rep(j, m)
                if (a[i][j] == '.') {
                    b[i]++;
                    c[j]++;
                }
        }
        int ans = n + m - 1;
        rep(i, n)
            rep(j, m)
                ans = min(ans, b[i] + c[j] - (a[i][j] == '.' ? 1 : 0));
        cout << ans << '\n';
    }
}