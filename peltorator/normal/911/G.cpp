#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << "Debug: " << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (1 << 19), T = 101;

int a[N];
int tree[N][T];

void push(int v)
{
    for (int i = 1; i <= 100; i++)
    {
        if (2 * v < N)
            tree[2 * v][i] = tree[v][tree[2 * v][i]];
        if (2 * v + 1 < N)
            tree[2 * v + 1][i] = tree[v][tree[2 * v + 1][i]];
    }
    for (int i = 1; i <= 100; i++)
        tree[v][i] = i;
}

void mem(int v, int l, int r)
{
    if (l + 1 >= r)
        return;
    push(v);
    int mid = (r + l) / 2;
    mem(2 * v, l, mid);
    mem(2 * v + 1, mid, r);
}

void upd(int v, int l, int r, int ql, int qr, int x, int y)
{
    if (r <= l)
        return;
   // push1(v);
    if (ql >= r || l >= qr)
        return;
    if (ql <= l && r <= qr)
    {
        for (int i = 1; i <= 100; i++)
            if (tree[v][i] == x)
                tree[v][i] = y;
      //  push[v] = {x, y};
        return;
    }
    int mid = (r + l) / 2;
    push(v);
    upd(2 * v, l, mid, ql, qr, x, y);
    upd(2 * v + 1, mid, r, ql, qr, x, y);
}

int f(int v, int l, int r, int q, int x)
{
    if (l + 1 == r)
        return tree[v][x];
    int mid = (r + l) / 2;
    if (q < mid)
        return f(2 * v, l, mid, q, x);
    return f(2 * v + 1, mid, r, q, x);
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        for (int j = 1; j <= 100; j++)
            tree[i][j] = j;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--;
        upd(1, 0, n, l, r, x, y);
    }
    mem(1, 0, n);
    for (int i = 0; i < n; i++)
        cout << f(1, 0, n, i, a[i]) << " ";
    return 0;
}