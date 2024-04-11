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
#define time tim

const int maxn = 500 * 1000 + 10;
int seg[maxn << 2][2][2];
bool laz[maxn << 2];
int h[2][maxn];
vector<int> adj[maxn];
int frm[maxn],
    too[maxn],
    vert[maxn],
    st[maxn],
    ft[maxn];
bool col[maxn];
int n, time;

void dfs(int u, int *h, bool fill_time, int p = -1) {
    if (p == -1)
        h[u] = 0;
    if (fill_time) {
        vert[time] = u;
        st[u] = time++;
    }
    for (auto e: adj[u]) {
        int v = frm[e] ^ too[e] ^ u;
        if (v ^ p) {
            h[v] = h[u] + 1;
            dfs(v, h, fill_time, u);
        }
    }
    if (fill_time)
        ft[u] = time;
}

void merge(int dst[][2], int le[][2], int ri[][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            dst[i][j] = max(le[i][j], ri[i][j]);
}

void build(int l = 0, int r = n, int id = 1) {
    if (r - l == 1) {
        memset(seg[id], 0, sizeof seg[id]);
        seg[id][0][0] = h[0][vert[l]];
        seg[id][0][1] = h[1][vert[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1 | 0);
    build(mid, r, id << 1 | 1);
    merge(seg[id], seg[id << 1 | 0], seg[id << 1 | 1]);
}

bool get_col(int idx, int l = 0, int r = n, int id = 1) {
    if (idx < l or r <= idx)
        return 0;
    if (r - l == 1)
        return laz[id];
    int mid = (l + r) >> 1;
    return get_col(idx, l, mid, id << 1 | 0)
        ^ get_col(idx, mid, r, id << 1 | 1)
        ^ laz[id];
}

void invert(int st, int en, int l = 0, int r = n, int id = 1) {
    if (st >= r or en <= l)
        return;
    if (st <= l and r <= en) {
        swap(seg[id][0][0], seg[id][1][0]);
        swap(seg[id][0][1], seg[id][1][1]);
        laz[id] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    invert(st, en, l, mid, id << 1 | 0);
    invert(st, en, mid, r, id << 1 | 1);
    merge(seg[id], seg[id << 1 | 0], seg[id << 1 | 1]);
    if (laz[id]) {
        swap(seg[id][0][0], seg[id][1][0]);
        swap(seg[id][0][1], seg[id][1][1]);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        frm[i] = fi;
        too[i] = se;
        col[i] = th;
        adj[fi].PB(i);
        adj[se].PB(i);
    }
    dfs(0, h[0], true);
    for (int i = 0; i + 1 < n; i++)
        if (h[0][frm[i]] > h[0][too[i]]) {
            swap(frm[i], too[i]);
        }

    int p1 = max_element(h[0], h[0] + n) - h[0];
    dfs(p1, h[0], false);
    int p2 = max_element(h[0], h[0] + n) - h[0];
    dfs(p2, h[1], false);

    build();
    for (int i = 0; i + 1 < n; i++)
        if (col[i])
            invert(st[too[i]], ft[too[i]]);

    int q;
    cin >> q;
    while (q--) {
        int id;
        cin >> id, id--;
        invert(st[too[id]], ft[too[id]]);
        int ans = 0;
        int c1 = get_col(st[p1]);
        int c2 = get_col(st[p2]);
        if (c1 == c2)
            cout << h[0][p2] << '\n';
        else
            cout << max(seg[1][c1][0], seg[1][c2][1]) << '\n';
    }
	return 0;
}