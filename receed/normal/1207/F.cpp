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

const int N = 500001, R = 500;
int a[N], c[R][R];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t, x, y;
    cin >> n;
    rep(i, n) {
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int j = 1; j < R; j++)
                c[j][x % j] += y;
        }
        else {
            if (x < R)
                cout << c[x][y] << '\n';
            else {
                int res = 0;
                for (int j = y; j < N; j += x)
                    res += a[j];
                cout << res << '\n';
            }
        }
    }	
}