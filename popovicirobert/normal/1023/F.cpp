#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;
const int LOG = 20;

struct Edge {
    int x, y;
    int cst;
    bool operator <(const Edge &other) const {
        return cst < other.cst;
    }
}edge[2 * MAXN + 1];

int sef[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    x = myfind(x), y = myfind(y);
    if(x != y) {
        sef[x] = y;
    }
}

vector < pair <int, int> > g[MAXN + 1];

int lvl[MAXN + 1], first[MAXN + 1], father[MAXN + 1];
int rmq[2 * MAXN + 1][LOG + 1], sz;
char lg[2 * MAXN + 1];

void dfs(int nod) {
    first[nod] = ++sz;
    rmq[sz][0] = nod;
    for(auto it : g[nod]) {
        if(it.first != father[nod]) {
            father[it.first] = nod;
            lvl[it.first] = lvl[nod] + 1;
            dfs(it.first);
            rmq[++sz][0] = nod;
        }
    }
}

inline void prec() {
    lvl[1] = 1;
    dfs(1);
    for(int i = 2; i <= sz; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(int bit = 1; (1 << bit) <= sz; bit++) {
        for(int i = 1; i + (1 << bit) <= sz + 1; i++) {
            int a = rmq[i][bit - 1], b = rmq[i + (1 << (bit - 1))][bit - 1];
            if(lvl[a] < lvl[b])
                rmq[i][bit] = a;
            else
                rmq[i][bit] = b;
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

int vals[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for(i = 1; i <= k; i++) {
        cin >> edge[i].x >> edge[i].y;
        edge[i].cst = 0;
    }
    for(i = 1; i <= m; i++) {
        cin >> edge[i + k].x >> edge[i + k].y >> edge[i + k].cst;
    }
    sort(edge + 1, edge + m + k + 1);
    vector <Edge> un_used;
    for(i = 1; i <= m + k; i++) {
        if(myfind(edge[i].x) != myfind(edge[i].y)) {
            myunion(edge[i].x, edge[i].y);
            g[edge[i].x].push_back({edge[i].y, edge[i].cst});
            g[edge[i].y].push_back({edge[i].x, edge[i].cst});
        }
        else {
            un_used.push_back(edge[i]);
        }
    }
    sort(un_used.begin(), un_used.end());
    memset(sef, 0, sizeof(sef));
    prec();
    for(auto it : un_used) {
        int x = it.x, y = it.y, cst = it.cst;
        int nod = get(x, y);
        while(lvl[x] > lvl[nod]) {
            if(vals[x] == 0) {
                vals[x] = cst;
            }
            myunion(x, father[x]);
            x = myfind(x);
        }
        while(lvl[y] > lvl[nod]) {
            if(vals[y] == 0) {
                vals[y] = cst;
            }
            myunion(y, father[y]);
            y = myfind(y);
        }
    }
    ll ans = 0;
    bool flag = 1;
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(it.second == 0 && lvl[i] < lvl[it.first]) {
                if(vals[it.first] == 0)
                    flag = 0;
                ans += vals[it.first];
            }
        }
    }
    if(flag == 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    //cin.close();
    //cout.close();
    return 0;
}