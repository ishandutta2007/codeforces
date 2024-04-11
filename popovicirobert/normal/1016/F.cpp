#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 3e5;

vector < pair <int, int> > g[MAXN + 1];
ll dst[MAXN + 1][2];
bool vis[MAXN + 1];

void dfs(int nod, ll d, bool type) {
    dst[nod][type] = d;
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it.first] == 0) {
            dfs(it.first, d + it.second, type);
        }
    }
}

bool cmp(int a, int b) {
    return dst[a][0] - dst[a][1] < dst[b][0] - dst[b][1];
}

ll aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos, ll val) {
    if(left == right) {
        aint[nod] = val;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos, val);
        else
            update(2 * nod + 1, mid + 1, right, pos, val);
        aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
    }
}

ll query(int nod, int left, int right, int l, int r) {
    if(l > r) {
        return -INF;
    }
    if(l <= left && right <= r) {
        return aint[nod];
    }
    else {
        int mid = (left + right) / 2;
        ll ans = -INF;
        if(l <= mid)
            ans = max(ans, query(2 * nod, left, mid, l, r));
        if(mid < r)
            ans = max(ans, query(2 * nod + 1, mid + 1, right, l, r));
        return ans;
    }
}

int pos[MAXN + 1], where[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y, z;
    ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&m);
    for(i = 1; i < n; i++) {
        scanf("%d%d%d" ,&x,&y,&z);
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(1, 0, 0);
    memset(vis, 0, sizeof(vis));
    dfs(n, 0, 1);
    for(i = 1; i <= n; i++) {
        pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, cmp);
    for(i = 1; i <= n; i++) {
        where[pos[i]] = i;
    }
    for(i = 1; i <= n; i++) {
        update(1, 1, n, i, dst[pos[i]][1]);
    }
    ll mx = 0;
    for(int nod = 1; nod <= n; nod++) {
        update(1, 1, n, where[nod], -INF);
        for(auto it : g[nod]) {
            update(1, 1, n, where[it.first], -INF);
        }
        int res = 0;
        for(int step = 1 << 18; step; step >>= 1) {
            if(res + step <= n && dst[nod][0] - dst[nod][1] > dst[pos[res + step]][0] - dst[pos[res + step]][1]) {
                res += step;
            }
        }
        mx = max(mx, dst[nod][0] + query(1, 1, n, res + 1, n));
        update(1, 1, n, where[nod], dst[nod][1]);
        for(auto it : g[nod]) {
            update(1, 1, n, where[it.first], dst[it.first][1]);
        }
    }
    while(m > 0) {
        m--;
        scanf("%d" ,&x);
        printf("%I64d\n" ,min(dst[n][0], mx + x));
    }
    //cin.close();
    //cout.close();
    return 0;
}