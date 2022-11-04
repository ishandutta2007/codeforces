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
long long INF = 1e17;
const long long m = 1000000007;
const int Y = 524288;
int sz = Y;
struct MC {
    int len;
    int mx;
    int lres, rres;
    bool lval, rval;
    MC(int LN = 0, int LR = 0, int RR = 0, int MX = 0, bool LV = false, bool RV = false) {
        len = LN;
        lres = LR;
        rres = RR;
        mx = MX;
        lval = LV;
        rval = RV;
    }
    MC(MC a, MC b) {
        len = a.len + b.len;
        lval = a.lval;
        rval = b.rval;
        mx = max(a.mx, b.mx);
        lres = a.lres;
        rres = b.rres;
        if (a.rval || b.lval) {
            mx = max(mx, a.rres + b.lres);
            if (a.lres == a.len)lres += b.lres;
            if (b.rres == b.len)rres += a.rres;
        }
    }
};
int ps[2 * Y];
MC tree[2][2 * Y];
void push(int tl, int tr, int v) {
    if (ps[v] == 1) {
        if (tl != tr) {
            ps[2 * v] ^= 1;
            ps[2 * v + 1] ^= 1;
        }
        ps[v] = 0;
        swap(tree[0][v], tree[1][v]);
    }
}
stack<MC>st;
void UPD(int ql, int qr, int v, int tl, int tr) {
    if (ql <= tl && tr <= qr) {
        ps[v] ^= 1;
        push(tl, tr, v);
        st.push(tree[0][v]);
        return;
    }
    push(tl, tr, v);
    int mid = (tr + tl) / 2;
    if (ql <= mid) {
        UPD(ql, qr, 2 * v, tl, mid);
    }
    else {
        push(tl, mid, 2 * v);
    }
    if (qr > mid) {
        UPD(ql, qr, 2 * v + 1, mid + 1, tr);
    }
    else {
        push(mid + 1, tr, 2 * v + 1);
    }
    tree[0][v] = MC(tree[0][2 * v], tree[0][2 * v + 1]);
    tree[1][v] = MC(tree[1][2 * v], tree[1][2 * v + 1]);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        char tmp;
        cin >> tmp;
        if (tmp == '<') {
            tree[0][i + sz] = MC(1, 1, 1, 1, true, false);
            tree[1][i + sz] = MC(1, 1, 1, 1, false, true);
        }
        else {
            tree[1][i + sz] = MC(1, 1, 1, 1, true, false);
            tree[0][i + sz] = MC(1, 1, 1, 1, false, true);
        }
    }
    for (int i = n; i < sz; ++i) {
        tree[0][i + sz] = MC(1);
        tree[1][i + sz] = MC(1);
    }
    for (int i = sz - 1; i >= 0; --i) {
        tree[0][i] = MC(tree[0][2 * i], tree[0][2 * i + 1]);
        tree[1][i] = MC(tree[1][2 * i], tree[1][2 * i + 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        UPD(l, r, 1, 0, sz - 1);
        while (st.size() > 1) {
            MC tmp = st.top();
            st.pop();
            MC tmp1 = st.top();
            st.pop();
            st.push(MC(tmp1, tmp));
        }
        cout << st.top().mx << "\n";
        st.pop();
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