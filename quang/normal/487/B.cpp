#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N  = 100100;
const long long MAX = 1000000000000ll;

int n, l;
long long s, a[N], gtmin[N][30], gtmax[N][30];
long long dp[N], tree[N * 4];

void Make_RMQ() {
    for(int i = 0; i <= n; i++) gtmin[i][0] = gtmax[i][0] = a[i];
    for(int j = 1; j <= log2(n) + 1; j++)
        for(int i = 0; i <= n - (1 << j) + 1; i++) {
            gtmin[i][j] = min(gtmin[i][j - 1], gtmin[i + (1 << (j - 1))][j - 1]);
            gtmax[i][j] = max(gtmax[i][j - 1], gtmax[i + (1 << (j - 1))][j - 1]);
        }
}

int Timvt(int x) {
    int l = 0, r = x;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        int k = log2(x - m + 1);
        long long amin, amax;
        amin = min(gtmin[m][k], gtmin[x - (1 << k) + 1][k]);
        amax = max(gtmax[m][k], gtmax[x - (1 << k) + 1][k]);
        if(amax - amin > s) l = m;
        else r = m;
    }
    return r;
}

long long Getmin(int node, int l, int r, int x, int y) {
    if(x > r || y < l) return MAX;
    if(x <= l && r <= y) return tree[node];
    int m = (l + r) >> 1;
    long long p1 = Getmin(node * 2, l, m, x, y);
    long long p2 = Getmin(node * 2 + 1, m + 1, r, x, y);
    return min(p1, p2);
}

void Update(int node, int l, int r, int id) {
    if(r < id || l > id) return;
    if(l == r) {
        tree[node] = dp[id];
        return;
    }
    int m = (l + r) >> 1;
    Update(node * 2, l, m, id);
    Update(node * 2 + 1, m + 1, r, id);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> s >> l;
    a[0] = MAX;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Make_RMQ();
    dp[0] = 0;
    for(int i = 0; i < N * 4; i++) tree[i] = MAX;
    Update(1, 0, n, 0);
    for(int i = 1; i <= n; i++) {
        int vt = Timvt(i);
        if(vt + l - 1 > i)
            dp[i] = MAX;
        else
            dp[i] = 1 + Getmin(1, 0, n, vt - 1, i - l);
        Update(1, 0, n, i);
    }
    if(dp[n] >= MAX) cout << -1;
    else cout << dp[n];
    return 0;
}