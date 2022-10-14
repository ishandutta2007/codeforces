#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ALL(vec) vec.begin(), vec.end()
using namespace std;
const int MAX_N = 200005;
int N_, Q_, coord_col[MAX_N];
class SegmentTree {
  private:
    int N;
    vector<int> segtree[MAX_N << 2ll];
    struct iii {
        long long fi, se, th;
        iii operator+(const iii& o) const {
            return {fi + o.fi, se + o.se, th + o.th};
        }
    };
  public:
    SegmentTree(int N) {
        this->N = N;
        build(1, 1, N);
    }
    void build(int node, int tl, int tr) {
        segtree[node].clear();
        if (tl == tr) {
            segtree[node].push_back(coord_col[tl]);
            return;
        }
        int c = (tl + tr) >> 1ll;
        build(node << 1ll, tl, c);
        build((node << 1ll) + 1, c + 1, tr);
        segtree[node].resize(tr - tl + 1);
        merge(ALL(segtree[node << 1ll]), ALL(segtree[(node << 1ll) + 1]), segtree[node].begin());
        return;
    }
    iii get_seg(int node, int tl, int tr, int le, int ri, int lo, int hi) {
        if (lo > hi || le > ri) {
            return {0, 0, 0};
        }
        if (ri < tl || tr < le || tl > tr) {
            return {0, 0, 0};
        }
        if (le <= tl && tr <= ri) {
            long long h1 = lower_bound(ALL(segtree[node]), hi + 1) - segtree[node].begin();
            long long h3 = upper_bound(ALL(segtree[node]), lo - 1) - segtree[node].begin();
            long long h2 = h1 - h3;
            return {tr - tl + 1 - h1, h2, h3};
        }
        int c = (tl + tr) >> 1ll;
        return get_seg(node << 1ll, tl, c, le, ri, lo, hi) + get_seg((node << 1ll) + 1, c + 1, tr, le, ri, lo, hi);
    }
    inline long long query(int le, int ri, int lo, int hi) {
        long long grid[11], ans = 0;
        iii A, B, C;
        A = get_seg(1, 1, N, 1, le - 1, lo, hi);
        B = get_seg(1, 1, N, le, ri, lo, hi);
        C = get_seg(1, 1, N, ri + 1, N, lo, hi);
        grid[1] = A.fi; grid[2] = B.fi; grid[3] = C.fi;
        grid[4] = A.se; grid[5] = B.se; grid[6] = C.se;
        grid[7] = A.th; grid[8] = B.th; grid[9] = C.th;
        ans += grid[5] * (N - grid[5]);
        ans += (grid[1] + grid[2] + grid[4]) * (grid[6] + grid[8] + grid[9]);
        ans += (grid[3] + grid[6]) * (grid[7] + grid[8]);
        ans += (grid[4] + grid[7]) * (grid[2] + grid[3]);
        ans -= grid[7] * grid[3];
        ans += ((grid[5] * (grid[5] - 1)) >> 1ll);
        return ans;
    }
};
int main() {
    int l, d, r, u, a, i;
    scanf("%d %d", &N_, &Q_);
    for (i = 1; i <= N_; ++i) scanf("%d", &coord_col[i]);
    SegmentTree solver(N_);
    for (i = 1; i <= Q_; ++i) {
        scanf("%d %d %d %d", &l, &d, &r, &u);
        printf("%I64d\n", solver.query(l, r, d, u));
    }
}