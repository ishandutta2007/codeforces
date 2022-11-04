#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
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
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
vector<int>compress(vector<int>h) {
    vector<int>vals = h;
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (auto& x : h)x = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    return h;
}
const int maxN = 300000, maxT = 2001;
struct SegTree {
    vector<int>treeMax;
    vector<int>p1;
    int sz;
    SegTree(int SZ = 1) {
        sz = SZ;
        treeMax.resize(2 * sz, INF);
        p1.resize(2 * sz, -1);
    }
    void pushMax(int v) {
        if (p1[v] == -1)return;
        treeMax[v] = p1[v];
        if (v < sz) {
            p1[2 * v] = p1[2 * v + 1] = p1[v];
        }
        p1[v] = -1;
    }
    int getMax(int ql, int qr, int v, int tl, int tr) {
        pushMax(v);
        if (ql <= tl && tr <= qr)return treeMax[v];
        int res = INF, m = (tr + tl) / 2;
        if (ql <= m)res = min(res, getMax(ql, qr, 2 * v, tl, m));
        else pushMax(2 * v);
        if (qr > m)res = min(res, getMax(ql, qr, 2 * v + 1, m + 1, tr));
        else pushMax(2 * v + 1);
        treeMax[v] = min(treeMax[2 * v], treeMax[2 * v + 1]);
        return res;
    }
    void setMax(int ql, int qr, int v, int tl, int tr, int val) {
        pushMax(v);
        if (ql <= tl && tr <= qr) {
            p1[v] = val;
            pushMax(v);
            return;
        }
        int m = (tr + tl) / 2;
        if (ql <= m)setMax(ql, qr, 2 * v, tl, m, val);
        else pushMax(2 * v);
        if (qr > m)setMax(ql, qr, 2 * v + 1, m + 1, tr, val);
        else pushMax(2 * v + 1);
        treeMax[v] = min(treeMax[2 * v], treeMax[2 * v + 1]);
    }
};
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    vector<int>h(n), dp(n, INF);
    for (auto& x : h)cin >> x;
    h = compress(h);
    int sz = 1;
    while (sz <= n + 2)sz <<= 1;
    dp[0] = 0;
    SegTree t1 = SegTree(sz), t2 = SegTree(sz);
    t1.setMax(h[0], sz - 1 , 1, 0, sz - 1, 0);
    t2.setMax(0, h[0], 1, 0, sz - 1, 0);
    for (int i = 1; i < n; ++i) {
        if (h[i] == h[i - 1]) {
            int tmp = dp[i - 1] + 1;
            dp[i] = tmp;
            t1.setMax(h[i], sz - 1, 1, 0, sz - 1, dp[i]);
            t2.setMax(0, h[i], 1, 0, sz - 1, dp[i]);
            continue;
        }
        if (h[i] < h[i - 1]) {
            int tmp = min(dp[i - 1], t1.getMax(h[i], h[i - 1] - 1, 1, 0, sz - 1)) + 1;
            dp[i] = tmp;
        }
        else {
            int tmp = min(dp[i - 1], t2.getMax(h[i - 1] + 1, h[i], 1, 0, sz - 1)) + 1;
            dp[i] = tmp;
        }
        t1.setMax(h[i], sz - 1, 1, 0, sz - 1, dp[i]);
        t2.setMax(0, h[i], 1, 0, sz - 1, dp[i]);
    }
    cout << dp.back();
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/