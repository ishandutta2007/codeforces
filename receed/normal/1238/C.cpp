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
	ll q, h, n;
    cin >> q;
    rep(z, q) {
        cin >> h >> n;
        vector<ll> a(n);
        rep(i, n)
            cin >> a[i];
        int cc = 1, ck = 0, ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] - a[i] == 1)
                cc++;
            else {
                if (cc % 2 == (ck > 0))
                    ans++;
                cc = 1;
                ck++;
            }
        }
        if (cc % 2 == (ck > 0) && a.back() > 1)
            ans++;
        cout << ans << '\n';
    }
}