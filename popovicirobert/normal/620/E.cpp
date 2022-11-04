#include <bits/stdc++.h>
#define ll long long
#define MAXN 400000

using namespace std;

vector <int> g[MAXN + 1];
int c[MAXN + 1];

bool viz[MAXN + 1];
int v[MAXN + 1];
int l[MAXN + 1], r[MAXN + 1];
int pos = 0;

void dfs(int nod) {
    v[++pos] = nod;
    l[nod] = pos;
    viz[nod] = 1;
    for(auto it : g[nod])
      if(viz[it] == 0)
          dfs(it);
    r[nod] = pos;
}

struct Aint {
    long long col;
    int lazy;
}aint[4 * MAXN + 1];

void build(int nod, int left, int right) {
    aint[nod].lazy = -1;
    if(left == right)
        aint[nod].col = (1LL << c[v[left]]);
    else {
        int med = (left + right) / 2;
        build(2 * nod, left, med);
        build(2 * nod + 1, med + 1, right);
        aint[nod].col = (aint[2 * nod].col | aint[2 * nod + 1].col);
    }
}

inline void prop(int nod) {
    if(2 * nod + 1 <= 4 * MAXN) {
        aint[2 * nod].lazy = aint[nod].lazy;
        aint[2 * nod + 1].lazy = aint[nod].lazy;
    }
}

inline void solve_lazy(int nod) {
    if(aint[nod].lazy >= 0) {
        aint[nod].col = (1LL << aint[nod].lazy);
        prop(nod);
        aint[nod].lazy = -1;
    }
}

void update(int nod, int left, int right, int l, int r, int col) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        aint[nod].lazy = col;
        solve_lazy(nod);
    }
    else {
        int med = (left + right) / 2;
        if(l <= med)
            update(2 * nod, left, med, l, r, col);
        if(med < r)
            update(2 * nod + 1, med + 1, right, l, r, col);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].col = (aint[2 * nod].col | aint[2 * nod + 1].col);
    }
}

ll ans;

void query(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r)
        ans |= aint[nod].col;
    else {
        int med = (left + right) / 2;
        if(l <= med)
            query(2 * nod, left, med, l, r);
        if(med < r)
            query(2 * nod + 1, med + 1, right, l, r);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].col = (aint[2 * nod].col | aint[2 * nod + 1].col);
    }
}

inline int check(ll val) {
    return __builtin_popcount(val >> 30) + __builtin_popcount(val & ((1LL << 30) - 1));
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, t, nod, col;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        cin >> c[i];
        c[i]--;
    }
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    build(1, 1, n);
    while(q > 0) {
        q--;
        cin >> t >> nod;
        if(t == 1) {
            cin >> col;
            col--;
            update(1, 1, n, l[nod], r[nod], col);
        }
        else {
            ans = 0;
            query(1, 1, n, l[nod], r[nod]);
            cout << check(ans) << endl;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}