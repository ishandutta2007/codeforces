#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
int a[MAXN + 1];

int dst[MAXN + 1][101];
int q[MAXN + 1];

inline void bfs(int type, int n) {
    int i, b = 0, e = 0;
    for(i = 1; i <= n; i++) {
        if(a[i] == type) {
            q[e++] = i;
            dst[i][type] = 1;
        }
    }
    while(b < e) {
        int nod = q[b];
        b++;
        for(auto it : g[nod]) {
            if(dst[it][type] == 0) {
                dst[it][type] = dst[nod][type] + 1;
                q[e++] = it;
            }
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, s, x, y, j;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i = 1; i <= k; i++) {
        bfs(i, n);
    }
    ll ans = 1e18;
    for(i = 1; i <= n; i++) {
        vector <int> cst;
        for(j = 1; j <= k; j++) {
            cst.push_back(dst[i][j]);
        }
        sort(cst.begin(), cst.end());
        ll cur = 0;
        for(j = 0; j < s; j++) {
            cur += cst[j];
        }
        cout << cur - s << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}