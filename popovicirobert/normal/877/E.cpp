#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

pair <int, int> ind[MAXN + 1];

int cnt = 0;

void dfs(int nod) {
    ind[nod].first = ++cnt;
    for(auto it : g[nod]) {
        dfs(it);
    }
    ind[nod].second = cnt;
}

struct Aint {
    int on, off;
    bool lazy;
}aint[4 * MAXN + 1];

inline void prop(int nod) {
    if(2 * nod + 1 <= 4 * MAXN) {
        aint[2 * nod].lazy ^= aint[nod].lazy;
        aint[2 * nod + 1].lazy ^= aint[nod].lazy;
    }
}

inline void solve_lazy(int nod) {
    prop(nod);
    if(aint[nod].lazy == 1)
        std::swap(aint[nod].on, aint[nod].off);
    aint[nod].lazy = 0;
}

void build(int nod, int left, int right, int pos, bool t) {
    if(left == right) {
        if(t == 0)
            aint[nod].off = 1;
        else
            aint[nod].on = 1;
    }
    else {
        int med = (left + right) / 2;
        if(pos <= med)
            build(2 * nod, left, med, pos, t);
        else
            build(2 * nod + 1, med + 1, right, pos, t);
        aint[nod].on = aint[2 * nod].on + aint[2 * nod + 1].on;
        aint[nod].off = aint[2 * nod].off + aint[2 * nod + 1].off;
    }
}

void update(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        aint[nod].lazy ^= 1;
        solve_lazy(nod);
    }
    else {
        int med = (left + right) / 2;
        if(l <= med)
            update(2 * nod, left, med, l, r);
        if(med < r)
            update(2 * nod + 1, med + 1, right, l, r);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].on = aint[2 * nod].on + aint[2 * nod + 1].on;
        aint[nod].off = aint[2 * nod].off + aint[2 * nod + 1].off;
    }
}

int query(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r)
        return aint[nod].on;
    else {
        int med = (left + right) / 2;
        int ans = 0;
        if(l <= med)
            ans += query(2 * nod, left, med, l, r);
        if(med < r)
            ans += query(2 * nod + 1, med + 1, right, l, r);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].on = aint[2 * nod].on + aint[2 * nod + 1].on;
        aint[nod].off = aint[2 * nod].off + aint[2 * nod + 1].off;
        return ans;
    }
}

string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, nod, p;
    bool t;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 2; i <= n; i++) {
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    for(i = 1; i <= n; i++) {
        cin >> t;
        build(1, 1, n, ind[i].first, t);
    }
    cin >> q;
    while(q > 0) {
        q--;
        str.clear();
        cin >> str;
        cin >> nod;
        if(str[0] == 'g')
            cout << query(1, 1, n, ind[nod].first, ind[nod].second) << "\n";
        else
            update(1, 1, n, ind[nod].first, ind[nod].second);
    }
    //cin.close();
    //cout.close();
    return 0;
}