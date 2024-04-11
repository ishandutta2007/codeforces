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

int n;

ll solve(vector<int> &a, ll &d) {
    int l = *min_element(all(a)), r = *max_element(all(a));
    d = r - l + 1;
    if (r - l + 1 <= 2)
        return 0;
    int l1 = -1, l2, r1 = -1, r2;
    rep(i, n + 1) {
        if (a[i] == l) {
            if (l1 == -1) l1 = i;
            l2 = i;
        }
        if (a[i] == r) {
            if (r1 == -1) r1 = i;
            r2 = i;
        }
    }
    if (l2 < r1 || r2 < l1)
        return 1;
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
    cin >> t;
    string s;
    rep(z, t) {
        cin >> s;
        n = s.size() + 1;
        vector<int> x(n + 1), y(n + 1);
        rep(i, n) {
            x[i + 1] = x[i];
            y[i + 1] = y[i];
            if (s[i] == 'W') y[i + 1]++;
            else if (s[i] == 'S') y[i + 1]--;
            else if (s[i] == 'A') x[i + 1]--;
            else if (s[i] == 'D') x[i + 1]++;
        }
        ll d1, d2, c1, c2;
        c1 = solve(x, d1);
        c2 = solve(y, d2);
        cout << min((d1 - c1) * d2, d1 * (d2 - c2)) << '\n';
    }
}