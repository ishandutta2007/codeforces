#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 500;

struct Query {
    int x, y;
    int t;
    bool operator <(const Query &other) const {
         return t < other.t;
    }
}qry[MAXN * MAXN + 1];

int sp[MAXN + 2][MAXN + 2];

int n, m, k;

inline bool check(int p) {
    int i, j;
    memset(sp, 0, sizeof(sp));
    for(i = 1; i <= p; i++)
        sp[qry[i].x][qry[i].y] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            sp[i][j] += sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
    for(i = k; i <= n; i++)
        for(j = k; j <= m; j++)
            if(sp[i][j] - sp[i - k][j] - sp[i][j - k] + sp[i - k][j - k] == k * k)
                return 1;
    return 0;
}

int main() {
    int q, i;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> q;
    for(i = 1; i <= q; i++)
        cin >> qry[i].x >> qry[i].y >> qry[i].t;
    sort(qry + 1, qry + q + 1);
    int rez = 0;
    for(int pas = 1 << 18; pas; pas >>= 1)
        if(rez + pas <= q && check(rez + pas) == 0)
            rez += pas;
    if(rez == q)
        cout << -1;
    else
        cout << qry[rez + 1].t;
    return 0;
}