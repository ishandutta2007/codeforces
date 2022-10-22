#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int oo = 1000000000;

const int V = 300100;
struct Node{
    int l, r, mi;
};
struct Tr{
    Node tr[4 * V];
    void init(int id, int l, int r) {
        tr[id].l = l;
        tr[id].r = r;
        tr[id].mi = oo;
        if (l == r) return;
        int mid = (l + r) / 2;
        init(id * 2, l, mid);
        init(id * 2 + 1, mid + 1, r);
    }
    void update(int id, int pos, int v) {
        if (tr[id].l == tr[id].r) {
            tr[id].mi = v;
            return;
        }
        int mid = (tr[id].l + tr[id].r) / 2;
        if (pos <= mid) update(id * 2, pos, v);
        else update(id * 2 + 1, pos, v);
        tr[id].mi = min(tr[id * 2].mi, tr[id * 2 + 1].mi);
    }
    int read(int id, int l, int r) {
        if (tr[id].l == l && tr[id].r == r) {
            return tr[id].mi;
        }
        int mid = (tr[id].l + tr[id].r) / 2;
        if (r <= mid) return read(id * 2, l, r);
        else if (l > mid) return read(id * 2 + 1, l, r);
        else {
            int a = read(id * 2, l, mid);
            int b = read(id * 2 + 1, mid + 1, r);
            return min(a, b);
        }
    }
}mi, mx;
int a[V], inc[V], de[V];
int in, dn;

int get_mi(int x) {
    int lo = 0, up = in - 1;
    while (lo != up) {
        int mid = (lo + up) / 2;
        if (inc[mid] > x) up = mid;
        else lo = mid + 1;
    }
    if (inc[lo] <= x) return lo + 1;
    else return lo;
}

int get_mx(int x) {
    int lo = 0, up = dn - 1;
    while (lo != up) {
        int mid = (lo + up) / 2;
        if (de[mid] < x) up = mid;
        else lo = mid + 1;
    }
    if (de[lo] >= x) return lo + 1;
    else return lo;
}
int n, dp[V];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        mi.init(1, 0, n - 1);
        mx.init(1, 0, n - 1);
        dp[0] = 0;
        in = dn = 1;
        inc[0] = de[0] = a[0];
        mi.update(1, 0, 0);
        mx.update(1, 0, 0);
        for (int i = 1; i < n; ++i) {
            int l_mi = get_mi(a[i]);
            int d_mi = mi.read(1, max(0, l_mi - 1), in - 1);
            int l_mx = get_mx(a[i]);
            int d_mx = mx.read(1, max(0, l_mx - 1), dn - 1);
            //printf("D %d %d %d %d\n", l_mi, d_mi, l_mx, d_mx);
            dp[i] = min(d_mi, d_mx) + 1;
            while (in > 0 && inc[in - 1] >= a[i]) {
                --in;
            }
            while (dn > 0 && de[dn - 1] <= a[i]) {
                --dn;
            }
            mi.update(1, in, dp[i]);
            inc[in++] = a[i];
            mx.update(1, dn, dp[i]);
            de[dn++] = a[i];
            //for (int j = 0; j < in; ++j) printf("%d ", inc[j]);puts("");
            //for (int j = 0; j < dn; ++j) printf("%d ", de[j]);puts("");
        }
        printf("%d\n", dp[n - 1]);
    }
    return 0;
}

/*
5
1 3 1 4 5
4
4 2 2 4
2
1 1
5
100 1 100 1 100
*/