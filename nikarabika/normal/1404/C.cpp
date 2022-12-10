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

const int maxn = 300 * 1000 + 100;
const int INF = 1000 * 1000 * 1000;
pii seg[maxn << 2];
int laz[maxn << 2];
int fen[maxn],
    ans[maxn],
    a[maxn],
    n, q;
vector<pii> vec[maxn];

void push(int, int, int);

pii merge(pii le, pii ri) {
    return min(le, ri);
}

void add(int val, int st, int en, int l = 0, int r = n, int id = 1) {
//    for (int i = st; i < en; i++)
//        seg[i].L += val;
//    return;
    if (st <= l and r <= en) {
        seg[id].L += val;
        laz[id] += val;
        return;
    }
    if (en <= l or st >= r)
        return;

    int mid = (l + r) >> 1;
    push(l, r, id);
    add(val, st, en, l, mid, id << 1 | 0);
    add(val, st, en, mid, r, id << 1 | 1);
    seg[id] = merge(seg[id << 1 | 0],
            seg[id << 1 | 1]);
}

pii seget(int st, int en, int l = 0, int r = n, int id = 1) {
//    pii ans = MP(INF, -1);
//    for (int i = st; i < en; i++)
//        ans = merge(ans, seg[i]);
//    return ans;
    if (st <= l and r <= en)
        return seg[id];
    if (st >= r or en <= l)
        return MP(INF, -1);
    int mid = (l + r) >> 1;
    push(l, r, id);
    return merge(seget(st, en, l, mid, id << 1 | 0),
            seget(st, en, mid, r, id << 1 | 1));
}

void push(int l, int r, int id) {
    if (laz[id]); else return;
    int mid = (l + r) >> 1;
    add(laz[id], l, mid, l, mid, id << 1 | 0);
    add(laz[id], mid, r, mid, r, id << 1 | 1);
    laz[id] = 0;
}

void build(int l = 0, int r = n, int id = 1) {
//    for (int i = 0; i < n; i++)
//        seg[i] = MP(0, i);
//    return;
    seg[id] = MP(0, l);
    if (r - l == 1)
        return;
    int mid = (l + r) >> 1;
    build(l, mid, id << 1 | 0);
    build(mid, r, id << 1 | 1);
}

void inc(int idx) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx]++;
}

int get(int idx) {
    int sum = 0;
    for (; idx; idx -= idx & -idx)
        sum += fen[idx];
    return sum;
}

int get(int st, int en) {
    return get(en) - get(st);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> q;
    build();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (i - a[i] >= 0)
            add(i - a[i], i, i + 1);
        else
            add(INF, i, i + 1);
    }
    for (int i = 0; i < q; i++) {
        int fi, se;
        cin >> fi >> se;
        se = n - se;
        vec[fi].PB(MP(se, i));
    }
    for (int i = n - 1; i >= 0; i--) {
        while (true) {
            pii min = seget(i, n);
            if (min.L > 0)
                break;
            add(-1, min.R + 1, n);
            add(INF, min.R, min.R + 1);
            inc(min.R);
            char x;
        }
        for (auto quer: vec[i])
            ans[quer.R] = get(i, quer.L);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
	return 0;
}