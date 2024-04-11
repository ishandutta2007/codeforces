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

const int maxn = 3e5 + 10;
const int INF = 10000 * 10000;
vector<pii> points;
int n;

struct segtree {
    int seg[maxn * 4];
    int laz[maxn * 4];
    int opcode;

    void clean() {
        memset(laz, 0, sizeof laz);
        memset(seg, 0, sizeof seg);
    }

    void push(int, int, int);

    int merge(int x, int y) {
        return opcode ? max(x, y) : min(x, y);
    }

    void fix(int val, int idx, int l = 0, int r = n, int id = 1) {
//        if (id == 1 and opcode)
//            cout << "segl " << idx << ' ' << val << endl;
//        if (id == 1 and !opcode)
//            cout << "segr " << idx << ' ' << val << endl;
        if (idx < l or idx >= r)
            return;
        if (r - l == 1) {
            seg[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        push(l, r, id);
        fix(val, idx, l, mid, id << 1 | 0);
        fix(val, idx, mid, r, id << 1 | 1);
        seg[id] = merge(seg[id << 1 | 0], seg[id << 1 | 1]);
    }

    void add(int val, int st, int en, int l = 0, int r = n, int id = 1) {
        if (st >= r or en <= l)
            return;
        if (st <= l and r <= en) {
            laz[id] += val;
            seg[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        push(l, r, id);
        add(val, st, en, l, mid, id << 1 | 0);
        add(val, st, en, mid, r, id << 1 | 1);
        seg[id] = merge(seg[id << 1 | 0], seg[id << 1 | 1]);
    }

    void log(int l = 0, int r = n, int id = 1) {
        if (r - l == 1) {
            cout << l << "->" << seg[id] << endl;
            return;
        }
        int mid = (l + r) >> 1;
        log(l, mid, id << 1 | 0);
        log(mid, r, id << 1 | 1);
    }
} segl, segr;

pii solve(int d) {
    int d2 = d + d;
    segl.clean();
    segr.clean();
    int p = 0,
        q = 0;
    for (int X = -d; X <= points[0].L; X++) {
        while (p < n and points[p].L <= X + d2) {
            segl.fix(points[p].R - d2, p);
            segr.fix(points[p].R - (points[p].L - X - d) + 1, p);
            p++;
        }
        while (q < p and points[q].L <= X + d) {
            segl.fix(points[q].R - (d + points[q].L - X), q);
            segr.fix(points[q].R + 1, q);
            q++;
        }
        //cout << "# " << p << ' ' << q << ' ' << segl.seg[1] << ' ' << segr.seg[1] << endl;
//        cout << X << " SEGL" << endl;
//        segl.log();
//        cout << X << " SEGR" << endl;
//        segr.log();
//        cout << endl;
        if (p == n and max(-d + (X == -d), segl.seg[1]) < segr.seg[1])
            return MP(X + d, max(0 + (X == -d), segl.seg[1] + d));
        segl.add(+1, 0, q);
        segr.add(+1, q, p);
    }
    return MP(-INF, -INF);
}

void add_point(int x, int y) {
    points.PB(MP(x, y));
}

void point_prep() {
    sort(all(points));
//    for (auto p: points)
//        cout << p.L << ' ' << p.R << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    segl.opcode = 1;
    segr.opcode = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = count(all(s), 'N');
        int y = count(all(s), 'B');
        add_point(x, y);
    }
    point_prep();
    int lo = -1,
        hi = 1e6 + 10;
    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        pii pos = solve(mid);
        if (pos.L == -INF)
            lo = mid;
        else
            hi = mid;
    }
    pii pos = solve(hi);
    cout << hi << endl;
    for (int i = 0; i < pos.L; i++)
        cout << 'N';
    for (int i = 0; i < pos.R; i++)
        cout << 'B';
    cout << '\n';
	return 0;
}

void segtree::push(int l, int r, int id) {
    if (!laz[id])
        return;
    int mid = (l + r) >> 1;
    add(laz[id], l, mid, l, mid, id << 1 | 0);
    add(laz[id], mid, r, mid, r, id << 1 | 1);
    laz[id] = 0;
}