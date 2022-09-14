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

const int N = 1 << 18;
pair<ll, ll> tr[N * 2];
ll mod[N * 2], a[N], ans[N];

void push(int v) {
    tr[v].first += mod[v];
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    mod[v] = 0;
}
void rel(int v) {
    tr[v] = min(tr[v * 2], tr[v * 2 + 1]);
}

void add(int cl, int cr, ll d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] += d;
        push(v);
        return;
    }
    push(v);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}        

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        tr[N + i] = {a[i], -i - 1};
    }
    for (int i = N - 1; i > 0; i--)
        tr[i] = min(tr[i * 2], tr[i * 2 + 1]);
    rep(i, n) {
        ll p = -tr[1].second - 1;
        ans[p] = i + 1;
        add(p, p + 1, 1e16);
        add(p + 1, n, -i - 1);
    }
    rep(i, n)
        cout << ans[i] << ' ';
}