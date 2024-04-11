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
const int Y = 400100;
const long long m = 1000000007;
struct MC {
    int j;
    int f;
    int mx;
    int add;
    MC(int J = 0, int F = 0, int MX = 0, int ADD = 0) {
        j = J;
        mx = MX;
        f = F;
        add = ADD;
    }
};
MC tree[4 * Y];
int n, sz = 1;
void PUSH(int tl, int tr, int v) {
    if (tl == tr) {
        tree[v].f += tree[v].add;
        tree[v].add = 0;
        tree[v].mx = tree[v].f + tree[v].j - n - 1;
    }
    else {
        tree[2 * v].add += tree[v].add;
        tree[2 * v + 1].add += tree[v].add;
        tree[v].mx += tree[v].add;
        tree[v].add = 0;
    }
}
void UPD(int ql, int qr, int v, int tl, int tr, int ad) {
    PUSH(tl, tr, v);
    if (ql <= tl && tr <= qr) {
        tree[v].add += ad;
        PUSH(tl, tr, v);
        return;
    }
    int mid = (tr + tl) / 2;
    if (ql <= mid) {
        UPD(ql, qr, 2 * v, tl, mid, ad);
    }
    if (qr > mid) {
        UPD(ql, qr, 2 * v + 1, mid + 1, tr, ad);
    }
    PUSH(tl, mid, 2 * v);
    PUSH(mid + 1, tr, 2 * v + 1);
    tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
}
int get(int ql, int qr, int v, int tl, int tr) {
    PUSH(tl, tr, v);
    if (ql <= tl && tr <= qr)return tree[v].mx;
    int mid = (tr + tl) / 2, res = 0;
    if (ql <= mid) {
        res = max(res, get(ql, qr, 2 * v, tl, mid));
    }
    if (qr > mid) {
        res = max(res, get(ql, qr, 2 * v + 1, mid + 1, tr));
    }
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k, m;
    cin >> n >> k >> m;
    while (sz <= (2 * n + 10))sz <<= 1;
    for (int i = sz; i < 2 * sz; ++i) {
        tree[i] = MC(i - sz, 0, i - sz - n - 1, 0);
    }
    for (int i = sz - 1; i > 0; --i) {
        tree[i].mx = max(tree[2 * i].mx, tree[2 * i + 1].mx);
    }
    set<pair<int, int>>vs;
    multiset<int>vals;
    while (m--) {
        int x, y;
        cin >> x >> y;
        int str = y + abs(x - k);
        if (vs.find(make_pair(x, y)) == vs.end()) {
            vs.insert(make_pair(x, y));
            UPD(1, str, 1, 0, sz - 1, 1);
            vals.insert(str);
        }
        else {
            vs.erase(vs.find(make_pair(x, y)));
            UPD(1, str, 1, 0, sz - 1, -1);
            vals.erase(vals.find(str));
        }
        if (vals.size() == 0) {
            cout << 0 << "\n";
            continue;
        }
        auto it = vals.end();
        --it;
        cout << max(0 ,get(1, *it, 1, 0, sz - 1)) << "\n";
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