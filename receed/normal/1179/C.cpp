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

const int N = 1 << 20;
int tr[N * 2], mod[N * 2];

void push(int v) {
    tr[v] += mod[v];
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    mod[v] = 0;
}

void rel(int v) {
    tr[v] = min(tr[v * 2], tr[v * 2 + 1]);
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
int getr(int v=1, int l=0, int r=N) {
    push(v);
    if (tr[v] >= 0)
        return -1;
    if (r - l == 1)
        return l;
    int x = getr(v * 2 + 1, (l + r) / 2, r);
    if (x >= 0)
        return x;
    return getr(v * 2, l, (l + r) / 2);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) {
        cin >> a[i];
        add(0, a[i] + 1, -1);
    }
    rep(i, m) {
        cin >> b[i];
        add(0, b[i] + 1, 1);
    }
    int t, pos, x, q;
    cin >> q;
    rep(i, q) {
        cin >> t >> pos >> x;
        pos--;
        if (t == 1) {
            add(0, a[pos] + 1, 1);
            a[pos] = x;
            add(0, a[pos] + 1, -1);
        }
        else {
            add(0, b[pos] + 1, -1);
            b[pos] = x;
            add(0, b[pos] + 1, 1);
        }
        int r = getr();
        cout << r << '\n';
    }
}