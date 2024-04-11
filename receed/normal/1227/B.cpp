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
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n), b(n), f(n + 1), c(n + 1);
        rep(i, n) {
            cin >> a[i];
            if (i == 0 || a[i] > a[i - 1]) {
                b[i] = a[i];
                f[a[i]] = 1;
            }
        }
        int p = 1;
        rep(i, n)
            if (!b[i]) {
                while (f[p])
                    p++;
                b[i] = p;
                p++;
            }
        int fl = 0;
        rep(i, n) {
            c[i + 1] = max(c[i], b[i]);
            if (c[i + 1] != a[i])
                fl = 1;
        }
        if (fl)
            cout << "-1";
        else
            rep(i, n)
                cout << b[i] << ' ';
        cout << '\n';
    }
}