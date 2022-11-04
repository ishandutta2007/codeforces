#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int LOG = 19;

vector <int> g[MAXN + 1], tree[2 * MAXN + 1];
int lvl[2 * MAXN + 1], low[MAXN + 1], cur;

vector <int> comp[MAXN + 1];
stack <int> stk;

void dfs(int nod) {
    stk.push(nod);
    for(auto it : g[nod]) {
        if(lvl[it] == 0) {
            lvl[it] = lvl[nod] + 1;
            low[it] = lvl[it];
            dfs(it);
            if(low[it] >= lvl[nod]) {
                cur++;
                while(stk.top() != it) {
                    comp[cur].push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                comp[cur].push_back(it);
                comp[cur].push_back(nod);
            }
            low[nod] = min(low[nod], low[it]);
        }
        else {
            low[nod] = min(low[nod], lvl[it]);
        }
    }
}

inline void make_tree(int n) {
    for(int i = 1; i <= cur; i++) {
        for(auto it : comp[i]) {
            tree[i + n].push_back(it);
            tree[it].push_back(i + n);
        }
    }
}

int rmq[4 * MAXN + 1][LOG + 1], first[2 * MAXN + 1], sz;
char lg[4 * MAXN + 1];

void dfs1(int nod, int par) {
    rmq[++sz][0] = nod;
    first[nod] = sz;
    lvl[nod] = lvl[par] + 1;
    for(auto it : tree[nod]) {
        if(it != par) {
            dfs1(it, nod);
            rmq[++sz][0] = nod;
        }
    }
}

inline void prec() {
    memset(lvl, 0, sizeof(lvl));
    dfs1(1, 0);
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

inline int get(int x, int y) {
    x = first[x], y = first[y];
    if(x > y) {
        swap(x, y);
    }
    int bit = lg[y - x + 1];
    if(lvl[rmq[x][bit]] < lvl[rmq[y - (1 << bit) + 1][bit]])
        return rmq[x][bit];
    return rmq[y - (1 << bit) + 1][bit];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, q;
    //ios::sync_with_stdio(false);
    //cin >> n >> m >> q;
    scanf("%d%d%d" ,&n,&m,&q);
    for(i = 1; i <= m; i++) {
        int x, y;
        //cin >> x >> y;
        scanf("%d%d" ,&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    lvl[1] = 1;
    dfs(1);
    make_tree(n);
    prec();
    while(q > 0) {
        q--;
        int x, y;
        //cin >> x >> y;
        scanf("%d%d" ,&x,&y);
        //cout << (lvl[x] + lvl[y] - 2 * lvl[get(x, y)]) / 2 << "\n";
        printf("%d\n" ,(lvl[x] + lvl[y] - 2 * lvl[get(x, y)]) / 2);
    }
    //cin.close();
    //cout.close();
    return 0;
}