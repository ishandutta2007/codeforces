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

ll inf = 2e9;
const int N = 1 << 18, MOD = 1e9 + 7;
ll sm[N];
pair<ll, ll> tr[N * 2];

pair<ll, ll> merge(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.first == p2.first)
        return {p1.first, (p1.second + p2.second) % MOD};
    return min(p1, p2);
}

void add(int v, pair<ll, ll> p) {
    tr[N + v] = p;
    for (int i = (N + v) / 2; i; i /= 2)
        tr[i] = merge(tr[i * 2], tr[i * 2 + 1]);
}

pair<ll, ll> getm(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return {inf, 1};
    if (cl <= l && r <= cr)
        return tr[v];
    return merge(getm(cl, cr, v * 2, l, (l + r) / 2), getm(cl, cr, v * 2 + 1, (l + r) / 2, r));
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n)
        cin >> a[i].second >> a[i].first;
    sort(all(a));
    sm[n] = inf;
    for (int i = n - 1; i >= 0; i--)
        sm[i] = min(sm[i + 1], a[i].second);
    rep(i, N * 2)
        tr[i] = {inf, 0};
    pair<ll, ll> ans = {inf, 1};
    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(all(a), make_pair(a[i].second, 0ll)) - a.begin();
        if (pos == n) {
            add(i, {a[i].first, 1});
            ans = merge(ans, {a[i].first, 1});
            continue;
        }
        int r = lower_bound(all(a), make_pair(sm[pos], 0ll)) - a.begin();
        auto t = getm(pos, r);
        t.first -= a[i].second - a[i].first;
        ans = merge(ans, t);
        add(i, t);
    }
    cout << ans.second;
}