#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;
const int LOG = 18;

vector <int> g[MAXN + 1];
int anc[MAXN + 1][LOG + 1], lvl[MAXN + 1];

int idl[MAXN + 1], idr[MAXN + 1], cur;
int which[MAXN + 1];

void dfs(int nod, int par) {
    anc[nod][0] = par;
    for(int bit = 1; bit <= LOG; bit++) {
        anc[nod][bit] = anc[anc[nod][bit - 1]][bit - 1];
    }
    idl[nod] = ++cur;
    which[cur] = nod;
    lvl[nod] = lvl[par] + 1;
    for(auto it : g[nod]) {
        dfs(it, nod);
    }
    idr[nod] = cur;
}

int rmq_mn[MAXN + 1][LOG + 1], rmq_mx[MAXN + 1][LOG + 1];
char lg[MAXN + 1];

inline int get_mn(int l, int r) {
    int bit = lg[r - l + 1];
    return min(rmq_mn[l][bit], rmq_mn[r - (1 << bit) + 1][bit]);
}

inline int get_mx(int l, int r) {
    int bit = lg[r - l + 1];
    return max(rmq_mx[l][bit], rmq_mx[r - (1 << bit) + 1][bit]);
}

inline int solve(int nod, int l, int r) {
    if(idl[nod] <= l && r <= idr[nod]) {
        return nod;
    }
    for(int bit = LOG; bit >= 0; bit--) {
        int cur = anc[nod][bit];
        if(cur > 0 && !(idl[cur] <= l && r <= idr[cur])) {
            nod = cur;
        }
    }
    return anc[nod][0];
}

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = 2; i <= n; i++) {
        int par;
        cin >> par;
        g[par].push_back(i);
    }
    lvl[0] = -1;
    dfs(1, 0);
    for(i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(i = 1; i <= n; i++) {
        rmq_mn[i][0] = rmq_mx[i][0] = idl[i];
    }
    for(int bit = 1; (1 << bit) <= n; bit++) {
        for(i = 1; i + (1 << bit) <= n + 1; i++) {
            rmq_mn[i][bit] = min(rmq_mn[i][bit - 1], rmq_mn[i + (1 << (bit - 1))][bit - 1]);
            rmq_mx[i][bit] = max(rmq_mx[i][bit - 1], rmq_mx[i + (1 << (bit - 1))][bit - 1]);
        }
    }
    while(q > 0) {
        q--;
        int l, r;
        cin >> l >> r;
        int mn = get_mn(l, r), mx = get_mx(l, r);
        int nod = solve(l, mn, mx);
        int a = which[mn], b = which[mx];
        int nod1, nod2;
        //////////// nod1
        int mn1 = MAXN + 1;
        int mx1 = 0;
        if(l < a) {
            mn1 = min(mn1, get_mn(l, a - 1));
            mx1 = max(mx1, get_mx(l, a - 1));
        }
        if(a < r) {
            mn1 = min(mn1, get_mn(a + 1, r));
            mx1 = max(mx1, get_mx(a + 1, r));
        }
        int aux1;
        if(a == l) {
            aux1 = r;
        }
        else {
            aux1 = l;
        }
        //////////// nod2
        int mn2 = MAXN + 1;
        int mx2 = 0;
        if(l < b) {
            mn2 = min(mn2, get_mn(l, b - 1));
            mx2 = max(mx2, get_mx(l, b - 1));
        }
        if(b < r) {
            mn2 = min(mn2, get_mn(b + 1, r));
            mx2 = max(mx2, get_mx(b + 1, r));
        }
        int aux2;
        if(b == l) {
            aux2 = r;
        }
        else {
            aux2 = l;
        }
        //////////
        nod1 = solve(aux1, mn1, mx1);
        nod2 = solve(aux2, mn2, mx2);
        if(lvl[nod1] > lvl[nod2]) {
            cout << a << " " << lvl[nod1] << "\n";
        }
        else {
            cout << b << " " << lvl[nod2] << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}