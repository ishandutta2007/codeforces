#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 1e17;
const int Y = 2000100;
const long long m = 1000000007;
long long a[Y];
long long tree[4 * Y];
long long b[Y];
long long pl[Y];
long long f[Y];
int sz;
void add(long long v, int ps) {
    ps += sz;
    while (ps) {
        tree[ps] = min(tree[ps], v);
        ps /= 2;
    }
}
long long get(int ql, int qr, int v, int tl, int tr) {
    if (ql <= tl && tr <= qr)return tree[v];
    long long res = INF;
    int mid = (tr + tl) / 2;
    if (ql <= mid)res = min(res, get(ql, qr, 2 * v, tl, mid));
    if (qr > mid)res = min(res, get(ql, qr, 2 * v + 1, mid + 1, tr));
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t = getint<int>();
    while (t--) {
        int n = getint<int>();
        sz = 1;
        while (sz <= 2 * (n + 1))sz <<= 1;
        for (int i = 0; i < 2 * sz; ++i)tree[i] = INF;
        for (int i = 0; i < n; ++i) {
            a[i] = getint<int>();
            a[i + n] = a[i];
        }
        for (int i = 0; i < n; ++i) {
            b[i] = getint<int>();
            b[i + n] = b[i];
        }
        f[0] = b[0] - a[0];
        add(f[0], 0);
        for (int i = 1; i < 2 * n; ++i) {
            f[i] = b[i] - a[i];
            long long ad = min(b[i - 1], a[i]);
            ad = min(ad, f[i - 1]);
            ad = max(ad, (long long)0);
            f[i] += ad;
            pl[i] = ad;
            add(f[i], i);
        }
        bool res = false;
        for (int i = 0; i < n && res == false; ++i) {
            if (pl[i] == 0) {
                res |= (get(i, i + n - 1, 1, 0, sz - 1) >= 0);
            }
        }
        if (res)cout << "YES\n";
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */