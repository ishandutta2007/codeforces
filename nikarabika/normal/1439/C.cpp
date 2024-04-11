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

const int maxn = 200 * 1000 + 10;
int minseg[maxn << 2],
    maxseg[maxn << 2],
    laz[maxn << 2];
LL sumseg[maxn << 2];

void push(int l, int r, int id);

int getless(LL val, int l = 0, int r = maxn, int id = 1) {
    if (r - l == 1)
        return l;
    int mid = (l + r) >> 1;
    if (laz[id]) push(l, r, id);
    if (minseg[id << 1 | 0] <= val)
        return getless(val, l, mid, id << 1 | 0);
    else
        return getless(val, mid, r, id << 1 | 1);
}

int getmore(LL val, int l = 0, int r = maxn, int id = 1) {
    if (r - l == 1)
        return l;
    int mid = (l + r) >> 1;
    if (laz[id]) push(l, r, id);
    if (sumseg[id << 1 | 0] > val)
        return getmore(val, l, mid, id << 1 | 0);
    else
        return getmore(val - sumseg[id << 1 | 0], mid, r, id << 1 | 1);
}

int modify(int st, int en, int val, int l = 0, int r = maxn, int id = 1) {
    if (st >= r or en <= l or minseg[id] >= val)
        return 0;
    if (st <= l and r <= en and maxseg[id] <= val) {
        laz[id] = val;
        maxseg[id] = val;
        minseg[id] = val;
        sumseg[id] = 1LL * val * (r - l);
        return 0;
    }
    int mid = (l + r) >> 1;
    if (laz[id]) push(l, r, id);
    modify(st, en, val, l, mid, id << 1 | 0);
    modify(st, en, val, mid, r, id << 1 | 1);
    maxseg[id] = maxseg[id << 1 | 0];
    minseg[id] = minseg[id << 1 | 1];
    sumseg[id] = sumseg[id << 1 | 0] + sumseg[id << 1 | 1];
    return 0;
}

LL getsum(int st, int en, int l = 0, int r = maxn, int id = 1) {
    if (st >= r or en <= l)
        return 0;
    if (st <= l and r <= en)
        return sumseg[id];
    int mid = (l + r) >> 1;
    if (laz[id]) push(l, r, id);
    return getsum(st, en, l, mid, id << 1 | 0)
        + getsum(st, en, mid, r, id << 1 | 1);
}

void push(int l, int r, int id) {
    int mid = (l + r) >> 1;
    modify(l, mid, laz[id], l, mid, id << 1 | 0);
    modify(mid, r, laz[id], mid, r, id << 1 | 1);
    laz[id] = 0;
}

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

int n;

int get(int pos, LL pool) {
    int ans = 0;
    while (pos < n) {
        int npos = min(n, getmore(getsum(0, pos) + pool));
        ans += npos - pos;
        pool -= getsum(pos, npos);
        pos = npos;
        if (pos == n) break;
        pos = getless(pool);
    }
    return ans;
}

int solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        modify(0, i + 1, x);
    }
    for (int i = 0; i < q; i++) {
        int ty, x, y;
        cin >> ty >> x >> y;
        if (ty == 1)
            modify(0, x, y);
        else
            cout << get(x - 1, y) << '\n';
    }
    return 0;
}