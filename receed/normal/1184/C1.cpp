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
	int n;
    cin >> n;
    int m = 4 * n + 1;
    vector<int> x(m), y(m);
    rep(i, m)
        cin >> x[i] >> y[i];
    rep(i, m) {
        int lx = 51, rx = -1, ly = 51, ry = -1;
        rep(j, m)
            if (i != j) {
                lx = min(lx, x[j]);
                ly = min(ly, y[j]);
                rx = max(rx, x[j]);
                ry = max(ry, y[j]);
            }
        if (ry - ly != rx - lx)
            continue;
        int fl = 0;
        rep(j, m)
            if (i != j && x[j] != lx && x[j] != rx && y[j] != ly && y[j] != ry)
                fl = 1;
        if (fl)
            continue;
        cout << x[i] << ' ' << y[i] << '\n';
        return 0;
    }
}