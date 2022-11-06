#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;
const int LOG = 18;

vector <int> g[MAXN + 1];
int p[MAXN + 1];

int rmq[2 * MAXN + 1][LOG + 1], first[MAXN + 1], sz;
char lg[2 * MAXN + 1];
int lvl[MAXN + 1];

void dfs(int nod, int par) {
    rmq[++sz][0] = nod;
    first[nod] = sz;
    lvl[nod] = lvl[par] + 1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod);
            rmq[++sz][0] = nod;
        }
    }
}

inline void prec(int n) {
    dfs(1, 0);
    for(int i = 2; i <= sz; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(int bit = 1; (1 << bit) <= sz; bit++) {
        for(int i = 1; i + (1 << bit) <= sz + 1; i++) {
            int a = rmq[i][bit - 1], b = rmq[i + (1 << (bit - 1))][bit - 1];
            if(lvl[a] < lvl[b]) {
                rmq[i][bit] = a;
            }
            else {
                rmq[i][bit] = b;
            }
        }
    }
}

inline int get_lca(int x, int y) {
    x = first[x], y = first[y];
    if(x > y) {
        swap(x, y);
    }
    int bit = lg[y - x + 1];
    int a = rmq[x][bit], b = rmq[y - (1 << bit) + 1][bit];
    if(lvl[a] < lvl[b]) {
        return a;
    }
    return b;
}

inline int get_dist(int x, int y) {
    return lvl[x] + lvl[y] - 2 * lvl[get_lca(x, y)];
}

struct Aint {
    int x, y;
    bool ok;
}aint[4 * MAXN + 1];

int where[MAXN + 1];

inline Aint combine(Aint a, Aint b) {
    if(a.ok == 0 || b.ok == 0) {
        return {0, 0, 0};
    }
    vector <int> nodes = {a.x, a.y, b.x, b.y};
    pair <int, int> aux;
    int mx = -1;
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(get_dist(nodes[i], nodes[j]) > mx) {
                aux = {nodes[i], nodes[j]};
                mx = get_dist(nodes[i], nodes[j]);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        if(get_dist(aux.first, nodes[i]) + get_dist(aux.second, nodes[i]) != mx) {
            return {0, 0, 0};
        }
    }
    return {aux.first, aux.second, 1};
}

void build(int nod, int left, int right) {
    if(left == right) {
        aint[nod] = {where[left], where[left], 1};
    }
    else {
        int mid = (left + right) / 2;
        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);
        aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
    }
}

void update(int nod, int left, int right, int l, int r) {
    if(left > r || right < l || (l < left && right < r)) {
        return ;
    }
    if(left == right) {
        aint[nod] = {where[left], where[left], 1};
    }
    else {
        int mid = (left + right) / 2;
        update(2 * nod, left, mid, l, r);
        update(2 * nod + 1, mid + 1, right, l, r);
        aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
    }
}

int ans;
void query(int nod, int left, int right, Aint &cur) {
    if(left == right) {
        Aint aux;
        if(cur.x == -1) {
            cur = aint[nod];
            ans = left;
        }
        else {
            aux = combine(aint[nod], cur);
            if(aux.ok == 1) {
                cur = aux;
                ans = left;
            }
        }
    }
    else {
        int mid = (left + right) / 2;
        Aint aux;
        if(cur.x == -1) {
            aux = aint[2 * nod];
        }
        else {
            aux = combine(aint[2 * nod], cur);
        }
        if(aux.ok == 1) {
            ans = mid;
            cur = aux;
            query(2 * nod + 1, mid + 1, right, cur);
        }
        else {
            query(2 * nod, left, mid, cur);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        where[p[i]] = i;
    }
    for(i = 2; i <= n; i++) {
        int par;
        cin >> par;
        g[par].push_back(i);
    }
    prec(n);
    build(1, 0, n - 1);
    cin >> q;
    while(q > 0) {
        q--;
        int t, a, b;
        cin >> t;
        if(t == 1) {
            cin >> a >> b;
            swap(p[a], p[b]);
            swap(where[p[a]], where[p[b]]);
            update(1, 0, n - 1, min(p[a], p[b]), max(p[a], p[b]));
        }
        else {
            Aint cur = {-1, -1, 1};
            ans = 0;
            query(1, 0, n - 1, cur);
            cout << ans + 1 << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}