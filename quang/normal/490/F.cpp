#include <bits/stdc++.h>
#define Task "F"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 6010;

vector <int> a[N];
int L[N], cnt, r[N], n, res = 0;

void Refresh() {
    L[0] = cnt = 0;
    for(int i = 1; i <= n + 1; i++) L[i] = 10000000;
}

void DFS(int u, int p) {
    int Oldval, Oldid, Oldcnt = cnt;
    if(cnt == 0 || r[u] > L[cnt])
        L[++cnt] = r[u];
    else {
        Oldid = lower_bound(L, L + n + 1, r[u]) - L;
        Oldval = L[Oldid];
        L[Oldid] = r[u];
    }
    res = max(res, cnt);
    for(int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(v != p)
            DFS(v, u);
    }
    if(Oldcnt != cnt) L[cnt--] = 10000000;
    else L[Oldid] = Oldval;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    int u, v;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        Refresh();
        DFS(i, 0);
    }
    cout << res;
    return 0;
}