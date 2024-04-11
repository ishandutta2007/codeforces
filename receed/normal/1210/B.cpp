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

const int N = 7001;
ll a[N], b[N], f[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    rep(i, n)
        cin >> a[i];
    rep(i, n)
        cin >> b[i];
    rep(i, n) {
        ll c = 0;
        rep(j, n)
            if (a[i] == a[j])
                c++;
        if (c >= 2)
            rep(j, n)
                if ((a[i] & a[j]) == a[j])
                    f[j] = 1;
    }
    ll ans = 0;
    rep(i, n)
        if (f[i])
            ans += b[i];
    cout << ans;
}