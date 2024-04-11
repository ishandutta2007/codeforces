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
	int n, k, m, t, q, p;
    cin >> n >> k >> m >> t;
    rep(i, t) {
        cin >> q >> p;
        if (q) {
            if (p <= k)
                k++;
            n++;
        }
        else {
            if (k <= p)
                n = p;
            else {
                k -= p;
                n -= p;
            }
        }
        cout << n << ' ' << k << '\n';
    }
}