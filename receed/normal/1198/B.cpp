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

const int N = 200001;
ll a[N];
ll t[N], p[N], x[N], used[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, q;
    cin >> n;
    rep(i, n)
        cin >> a[i];
    cin >> q;
    rep(i, q) {
        cin >> t[i] >> p[i];
        if (t[i] == 1) {
            p[i]--;
            cin >> x[i];
        }
    }
    ll cm = 0;
    for (int i = q - 1; i >= 0; i--) {
        if (t[i] == 2)
            cm = max(cm, p[i]);
        else if (!used[p[i]]) {
            used[p[i]] = 1;
            a[p[i]] = max(x[i], cm);
        }
    }
    rep(i, n) {
        if (!used[i])
            a[i] = max(a[i], cm);
        cout << a[i] << ' ';
    }
}