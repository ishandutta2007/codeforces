//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

//#define COMB_TRIPLE
//const int maxcomb = 1000 * 1000 + 100;
//#define COMB_DP
//const int maxcomb = 5000 + 10;

const LL Mod = 1000 * 1000 * 1000 + 7;
//const LL Mod = 998244353;

const LL INF = 1e18;

struct SegmentTree {
    pll *seg;
    vector<int> *segs;
    LL *lazval;
    bool *laz;
    int segL, segR;

    SegmentTree(int segl, int segr) {
        segL = segl;
        segR = segr;
        int len = segr - segl + 5;
        int segsz = len << 2;
        seg = new pll[segsz];
        segs = new vector<int>[segsz];
        laz = new bool[segsz];
        lazval = new LL[segsz];
    }

    pll build(int l, int r, int id) {
        seg[id] = pll(INF - 1, l);
        laz[id] = false;
        lazval[id] = 0;
        if (r - l == 1)
            return seg[id];
        int mid = (l + r) >> 1;
        return seg[id] = min(build(l, mid, id << 1 | 0),
                build(mid, r, id << 1 | 1));
    }
    pll build() {
        return build(segL, segR, 1);
    }
    int addObs(int st, int en, int val, int l, int r, int id) {
        if (st >= r or en <= l)
            return 0;
        if (st <= l and r <= en) {
            segs[id].PB(val);
            return 0;
        }
        int mid = (l + r) >> 1;
        addObs(st, en, val, l, mid, id << 1 | 0);
        addObs(st, en, val, mid, r, id << 1 | 1);
        return 0;
    }
    int addObs(int st, int en, int val) { return addObs(st, en, val, segL, segR, 1); }

    int getObs(int idx, int l, int r, int id) {
        if (idx < l or r <= idx)
            return -1;
        if (sz(segs[id])) {
            int res = segs[id].back();
            segs[id].pop_back();
            return res;
        }
        if (r - l == 1) {
            return -1;
        }
        int mid = (l + r) >> 1;
        return max(getObs(idx, l, mid, id << 1 | 0),
                getObs(idx, mid, r, id << 1 | 1));
    }
    int getObs(int idx) { return getObs(idx, segL, segR, 1); }

    pll invalidate(int idx, int l, int r, int id) {
        if (idx < l or r <= idx)
            return seg[id];
        if (r - l == 1)
            return seg[id] = pll(INF, l);
        int mid = (l + r) >> 1;
        if (laz[id])
            push(l, r, id);
        return seg[id] = min(invalidate(idx, l, mid, id << 1 | 0),
                invalidate(idx, mid, r, id << 1 | 1));
    }
    pll invalidate(int idx) { return invalidate(idx, segL, segR, 1); }

    pll getMin() {
        return seg[1];
    }

    pll setMin(int st, int en, LL val, int l, int r, int id) {
        if (st >= r or en <= l)
            return seg[id];
        if (st <= l and r <= en) {
            if (laz[id] == 0 or (laz[id] == 1 and lazval[id] > val)) {
                laz[id] = 1;
                lazval[id] = val;
                if (seg[id].L < INF)
                    smin(seg[id].L, val);
            }
            return seg[id];
        }
        int mid = (l + r) >> 1;
        if (laz[id])
            push(l, r, id);
        return seg[id] = min(setMin(st, en, val, l, mid, id << 1 | 0),
                setMin(st, en, val, mid, r, id << 1 | 1));
    }
    pll setMin(int st, int en, LL val) { return setMin(st, en, val, segL, segR, 1); }

    void push(int l, int r, int id) {
        int mid = (l + r) >> 1;
        setMin(l, mid, lazval[id], l, mid, id << 1 | 0);
        setMin(mid, r, lazval[id], mid, r, id << 1 | 1);
        laz[id] = 0;
    }
};

int solve();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
    q = 1;
	while (q--)
		solve();
	return 0;
}

const int maxn = 100 * 1001;
bool mark[maxn];
pii frm[maxn],
    too[maxn];
int ty[maxn];
LL cst[maxn];
int n, q, src;

int solve() {
    cin >> n >> q >> src;
    src--;
    SegmentTree seg(0, n);
    seg.build();
    for (int i = 0; i < q; i++) {
        cin >> ty[i];
        if (ty[i] == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            frm[i] = MP(u, u + 1);
            too[i] = MP(v, v + 1);
        }
        else if (ty[i] == 2) {
            int u, l, r;
            cin >> u >> l >> r;
            u--, l--;
            frm[i] = MP(u, u + 1);
            too[i] = MP(l, r);
        }
        else {
            int u, l, r;
            cin >> u >> l >> r;
            u--, l--;
            frm[i] = MP(l, r);
            too[i] = MP(u, u + 1);
        }
        cin >> cst[i];
        seg.addObs(frm[i].L, frm[i].R, i);
    }
    LL ans[n];
    memset(ans, -1, sizeof ans);
    seg.setMin(src, src + 1, 0);
    while (true) {
        pll st = seg.getMin();
        if (st.L >= INF - 10)
            break;
        ans[st.R] = st.L;
        while (true) {
            int segid = seg.getObs(st.R);
            if (segid == -1) break;
            if (mark[segid]) continue;
            mark[segid] = true;
            seg.setMin(too[segid].L, too[segid].R, st.L + cst[segid]);
        }
        seg.invalidate(st.R);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}