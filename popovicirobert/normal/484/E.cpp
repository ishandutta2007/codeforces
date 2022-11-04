#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;
const int INF = 1e5;

struct Aint {
    ll pref, suff, sum;
    ll best;
}aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos) {
    if(left == right) {
        aint[nod] = {1, 1, 1, 1};
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid) {
            update(2 * nod, left, mid, pos);
        }
        else {
            update(2 * nod + 1, mid + 1, right, pos);
        }
        aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;
        aint[nod].best = max(aint[2 * nod].best, max(aint[2 * nod + 1].best, aint[2 * nod].suff + aint[2 * nod + 1].pref));
        aint[nod].pref = max(aint[2 * nod].pref, aint[2 * nod].sum + aint[2 * nod + 1].pref);
        aint[nod].suff = max(aint[2 * nod + 1].suff, aint[2 * nod + 1].sum + aint[2 * nod].suff);
    }
}

int query(int nod, int left, int right, int l, int r, int &cur) {
    if(l <= left && right <= r) {
        int ans = max(0LL, max(cur + aint[nod].pref, aint[nod].best));
        cur = max(0LL, max(cur + aint[nod].sum, aint[nod].suff));
        return ans;
    }
    else {
        int mid = (left + right) / 2;
        int ans = 0;
        if(l <= mid) {
            ans = max(ans, query(2 * nod, left, mid, l, r, cur));
        }
        if(mid < r) {
            ans = max(ans, query(2 * nod + 1, mid + 1, right, l, r, cur));
        }
        return ans;
    }
}

struct Query {
    int l, r, w;
}qry[MAXN + 1];

pair <int, int> res[MAXN + 1], h[MAXN + 1];
int n, m;

inline void solve(int step) {
    int i;
    for(i = 1; i <= 4 * n; i++) {
        aint[i] = {-INF, -INF, -INF, -INF};
    }
    sort(res + 1, res + m + 1);
    int pos = n;
    for(i = m; i >= 1; i--) {
        while(pos >= 1 && h[pos].first >= res[i].first + step) {
            update(1, 1, n, h[pos].second);
            pos--;
        }
        int p = res[i].second;
        int cur = 0;
        if(query(1, 1, n, qry[p].l, qry[p].r, cur) >= qry[p].w) {
            res[i].first += step;
        }
    }
}

int sol[MAXN + 1];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }
    sort(h + 1, h + n + 1);
    cin >> m;
    for(i = 1; i <= m; i++) {
        cin >> qry[i].l >> qry[i].r >> qry[i].w;
        res[i] = {0, i};
    }
    for(int step = 1 << 29; step; step >>= 1) {
        solve(step);
    }
    for(i = 1; i <= m; i++) {
        sol[res[i].second] = res[i].first;
    }
    for(i = 1; i <= m; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}