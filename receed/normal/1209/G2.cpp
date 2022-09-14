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

struct f {
    int mn, mx, mod, lx, rx, sx;

    f operator+(f x) {
        if (mn < x.mn)
            return {mn, max(mx, x.mx), 0, lx, max(rx, x.mx), sx};
        if (mn > x.mn)
            return {x.mn, max(mx, x.mx), 0, max(mx, x.lx), x.rx, x.sx};
        return {mn, max(mx, x.mx), 0, lx, x.rx, sx + x.sx + max(rx, x.lx)};
    }
};

const int N = 1 << 18;
int a[N], ps[N], n;
set<int> ls[N];
f t[N * 2];

void push(int v) {
    t[v].mn += t[v].mod;
    if (v < N) {
        t[v * 2].mod += t[v].mod;
        t[v * 2 + 1].mod += t[v].mod;
    }
    t[v].mod = 0;
}

void rel(int v) {
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void add(int cl, int cr, int d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v);
        return;
    }
    if (cl <= l && r <= cr) {
        t[v].mod += d;
        push(v);
        return;
    }
    push(v);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

int qu() {
    return n - (t[1].lx + t[1].rx + t[1].sx);
}

void cx(int p, int x, int v=1, int l=0, int r=N) {
    push(v);
    if (r - l == 1) {
        t[v].lx = t[v].mx = x;
        return;
    }
    if (p < (l + r) / 2) {
        cx(p, x, v * 2, l, (l + r) / 2);
        push(v * 2 + 1);
    }
    else {
        push(v * 2);
        cx(p, x, v * 2 + 1, (l + r) / 2, r);
    }
    rel(v);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int q, p, x;
    cin >> n >> q;
    rep(i, N) {
        if (i < n)
            cin >> a[i];
        else
            a[i] = N - 1;
        ls[a[i]].insert(i);
    }
    n = N;
    rep(i, n)
        if (i == *ls[a[i]].begin())
            t[N + i].lx = t[N + i].mx = ls[a[i]].size();
    for (int i = N - 1; i; i--)
        rel(i);
    rep(i, N)
        if (!ls[i].empty())
            add(*ls[i].begin(), *--ls[i].end(), 1);
    cout << qu() << '\n';
    rep(z, q) {
        cin >> p >> x;
        p--;
        cx(*ls[a[p]].begin(), 0);
        add(*ls[a[p]].begin(), *--ls[a[p]].end(), -1);
        ls[a[p]].erase(p);
        if (!ls[a[p]].empty()) {
            add(*ls[a[p]].begin(), *--ls[a[p]].end(), 1);
            cx(*ls[a[p]].begin(), ls[a[p]].size());
        }
        if (!ls[x].empty()) {
            add(*ls[x].begin(), *--ls[x].end(), -1);
            cx(*ls[x].begin(), 0);
        }
        ls[x].insert(p);
        add(*ls[x].begin(), *--ls[x].end(), 1);
        cx(*ls[x].begin(), ls[x].size());
        a[p] = x;
        cout << qu() << '\n';
    }
    for (int i = 1; i < N; i++)
        push(i);
}