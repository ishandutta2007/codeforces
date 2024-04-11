/*
    https://codeforces.com/contest/855/problem/F
 
    Description:
    Maintain minimum positive valued snake and
    maximum negative valued snake. If at i one
    is uninitialized, then sum is 0. Otherwise,
    sum is sum of minimum positive value - maximum
    negative value (or minimum positive value +
    absolute minimum negative value).
 
*/
 
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e11;

struct SegmentTreeBeats {
    struct Info {
        lint max_v = INF;
        lint smax_v = INF;
        lint max_c = 0;
        lint lazy = INF;
        lint sum = 0;
 
        friend inline Info merge(Info a, Info b) {
            if (a.max_v < b.max_v) {
                a.smax_v = a.max_v;
                a.max_v = b.max_v;
                a.max_c =  0;
            }
 
            if (a.max_v == b.max_v) {
                a.max_c += b.max_c;
                a.smax_v = max(a.smax_v, b.smax_v);
            } else {
                a.smax_v = max(a.smax_v, b.max_v);
            }
 
            a.sum += b.sum;
            a.lazy = INF;

            return a;
 
        }
 
    };
 
    struct Node {
        array<Info, 2> info;

        inline Info & operator [] (int n) {
            return info[n];
        }

        inline const Info & operator [] (int n) const {
            return info[n];
        }

        inline void set_min(int sign, lint x) {
            if (x >= info[sign].max_v) return;
            info[sign].sum += 1ll * (x - info[sign].max_v) * info[sign].max_c;
            info[sign].max_v = info[sign].lazy = x;
        }
 
        friend inline Node merge(Node a, Node b) {
            for (int i = 0; i < 2; i++) 
                a[i] = merge(a[i], b[i]);

            return a;
        }
 
    };
 
    vector<Node> tree;

    SegmentTreeBeats(int n = 0) {
        tree.resize(4 * n);
        build(1, 1, n);
    }
 
    void build(int n, int tl, int tr) {
        if (tl == tr) return;
        int mid = (tl + tr) / 2;
 
        build(n * 2, tl, mid);
        build(n * 2 + 1, mid + 1, tr);
        
        tree[n] = merge(tree[n * 2], tree[n * 2 + 1]);
    }
 
    inline void lazydown(lint n) {
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                tree[n * 2 + j].set_min(i, tree[n][i].lazy);

        tree[n][0].lazy = tree[n][1].lazy = INF;
    }
 
    void update(int n, int tl, int tr, int le, int ri, lint x, int sign) {
        if (tr < le || ri < tl || tl > tr || tree[n][sign].max_v <= x) return;
        if (tl == tr) {
            tree[n][sign].max_v = x;
            tree[n][sign].smax_v = -INF;
            if (tree[n][sign ^ 1].max_v != INF) {
                tree[n][sign].sum = x;
                tree[n][sign].max_c = 1;
                tree[n][sign ^ 1].sum = tree[n][sign ^ 1].max_v;
                tree[n][sign ^ 1].max_c = 1;
            }
            return;
        }

        if (le <= tl && tr <= ri && tree[n][sign].smax_v < x) 
            return tree[n].set_min(sign, x);
 
        lazydown(n);
        int mid = (tl + tr) / 2;
        
        update(n * 2, tl, mid, le, ri, x, sign);
        update(n * 2 + 1, mid + 1, tr, le, ri, x, sign);
        
        tree[n] = merge(tree[n * 2], tree[n * 2 + 1]);
    }

    lint query(int n, int tl, int tr, int le, int ri) {
        if (tr < le || ri < tl || tl > tr) return 0;
        if (le <= tl && tr <= ri) return tree[n][0].sum + tree[n][1].sum;

        lazydown(n);
        int mid = (tl + tr) / 2;

        return query(n * 2, tl, mid, le, ri) + query(n * 2 + 1, mid + 1, tr, le, ri);
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int N, Q;
    N = 1e5;
    cin >> Q;

    for (SegmentTreeBeats solver(N); Q > 0; Q--) {
        lint type, l, r, k;
        cin >> type;
 
        switch (type) {
            case 1:
                cin >> l >> r >> k; r--;
                solver.update(1, 1, N, l, r, abs(k), k > 0);
                break;
 
            case 2:
                cin >> l >> r; r--;
                cout << solver.query(1, 1, N, l, r) << "\n";
                break;
 
            default:
                break;
        }
    }
 
    return 0;
 
}