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
	ll n, b;
    cin >> n >> b;
    b = b * 8 / n;
    ll d = n;
    if (b < 20)
        d = min(d, 1ll << b);
    vector<int> a(n);
    rep(i, n)
        cin >> a[i];
    sort(all(a));
    vector<int> ps(1, 0);
    int l = -1;
    for (int i : a) {
        if (l == i)
            ps.back()++;
        else {
            ps.push_back(ps.back() + 1);
            l = i;
        }
    }
    if ((int) ps.size() - 1 <= d) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    rep(i, ps.size() - d)
        ans = max(ans, ps[i + d] - ps[i]);
    cout << n - ans;
}