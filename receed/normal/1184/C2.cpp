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

const int N = 1 << 23, D = 1e6;
int tr[N * 2], mod[N * 2];

void push(int v) {
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    tr[v] += mod[v];
    mod[v] = 0;
}
void rel(int v) {
    tr[v] = max(tr[v * 2], tr[v * 2 + 1]);
}

void add(int cl, int cr, int d, int v=1, int l=0, int r=N) {
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

int getmx(int cl, int cr, int v=1, int l=0, int r=N) {
    push(v);
    if (cr <= l || r <= cl)
        return -N;
    if (cl <= l && r <= cr)
        return tr[v];
    return max(getmx(cl, cr, v * 2, l, (l + r) / 2), getmx(cl, cr, v * 2 + 1, (l + r) / 2, r));
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, r, cx, cy;
    cin >> n >> r;
    vector<pair<int, int>> a(n);
    rep(i, n) {
        cin >> cx >> cy;
        a[i] = {cx - cy, cx + cy + 2 * D};
        assert(a[i].second >= 0);
    }
    r = r * 2 + 1;
    sort(all(a));
    int p = 0, ans = 0;
    rep(i, n) {
        while (a[i].first - a[p].first >= r) {
            add(a[p].second, a[p].second + r, -1);
            p++;
        }
        add(a[i].second, a[i].second + r, 1);
        ans = max(ans, getmx(0, N));
    }
    cout << ans << '\n';
}