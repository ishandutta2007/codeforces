#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);
const int N = (int)1e5;

using namespace std;

struct segm_tree {
    int t[(1 << 18)][2];
    bool sw[(1 << 18)];
    int sz;

    segm_tree() {}

    segm_tree(int _sz) {
         sz = 1;
         while (sz < _sz) sz *= 2;
         memset(t, 0, sizeof t);
         memset(sw, 0, sizeof sw);
    }

    void push(int v, int tl, int tr) {
        if  (tl == tr || !sw[v]) return;
        sw[v * 2] ^= 1;
        sw[v * 2 + 1] ^= 1;
        sw[v] = 0;
        swap(t[v][0], t[v][1]);
    }

    void put(int v, int tl, int tr, int id, bool x) {
        if  (tl == tr && tl == id) {
            t[v][x] = 1;
            t[v][1 - x] = 0;
            return;
        }

        int tm = (tl + tr) / 2;
        if  (id <= tm)
            put(v * 2, tl, tm, id, x);
        else
            put(v * 2 + 1, tm + 1, tr, id, x);

        forn(i, 2)
            t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
    }

    void put(int id, bool x) {
        put(1, 0, sz - 1, id, x);
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if  (tl == l && tr == r)
            return sw[v] ? t[v][0] : t[v][1];
        push(v, tl, tr);

        int tm = (tl + tr) / 2;
        if  (r <= tm)
            return sum(v * 2, tl, tm, l, r);
        else if  (tm < l)
            return sum(v * 2 + 1, tm + 1, tr, l, r);
        else
            return sum(v * 2, tl, tm, l, tm) + sum(v * 2 + 1, tm + 1, tr, tm + 1, r);
    }

    int sum(int l, int r) {
        return sum(1, 0, sz - 1, l, r);
    }

    void go(int v, int tl, int tr, int l, int r) {
        if  (tl == l && tr == r) {
            sw[v] ^= 1;
            return;
        }

        push(v, tl, tr);

        int tm = (tl + tr) / 2;
        if  (r <= tm)
            go(v * 2, tl, tm, l, r);
        else if  (tm < l)
            go(v * 2 + 1, tm + 1, tr, l, r);
        else
            go(v * 2, tl, tm, l, tm), go(v * 2 + 1, tm + 1, tr, tm + 1, r);

        forn(i, 2)
            t[v][i] = (sw[v * 2] ? t[v * 2][1 - i] : t[v * 2][i]) + (sw[v * 2 + 1] ? t[v * 2 + 1][1 - i] : t[v * 2 + 1][i]);
    }

    void go(int l, int r) {
        go(1, 0, sz - 1, l, r);
    }
} t[20];

int n, m;
int a[N + 10];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;

  forn(j, 20)
    t[j] = segm_tree(n);

  forn(i, n) {
    scanf("%d", &a[i]);
    forn(j, 20)
        if  ((1 << j) & a[i])
            t[j].put(i, 1);
        else
            t[j].put(i, 0);
  }


  cin >> m;
  forn(i, m) {
    int T;
    scanf("%d", &T);
    if  (T == 1) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--; r--;

        LL res = 0;
        forn(j, 20)
            res += (1LL * t[j].sum(l, r)) * (1LL << j);

        printf("%I64d\n", res);
    } else {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--; r--;
        forn(j, 20)
            if  ((1 << j) & x)
                t[j].go(l, r);
    }
  }

  return 0;
}