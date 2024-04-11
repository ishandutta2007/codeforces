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

const int N = 1001;
ll a[N][N];

ll f(ll x, ll y, ll z) {
    return (ll) round(sqrt((ld) (a[x][y] * a[x][z] / a[y][z])));
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    rep(i, n)
        rep(j, n)
            cin >> a[i][j];
    cout << f(0, 1, 2) << ' ' << f(1, 0, 2) << ' ';
    for (int i = 2; i < n; i++)
        cout << f(i, 0, 1) << ' ';
}