#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int LOG = 17;

vector <int> g[MAXN + 1];
int w[MAXN + 1], lvl[MAXN + 1];

ll sp[MAXN + 1];
int anc[MAXN + 1][LOG + 1];

void dfs(int nod, int par) {
    lvl[nod] = lvl[par] + 1;
    sp[nod] = sp[par] + w[nod];
    anc[nod][0] = par;
    for(int bit = 1; bit <= 17; bit++) {
        anc[nod][bit] = anc[anc[nod][bit - 1]][bit - 1];
    }
    for(auto it : g[nod]) {
        dfs(it, nod);
    }
}

int id[MAXN + 1];
int l, ans;
ll s;

inline int get(int nod) {
    int aux = nod;
    for(int bit = 17; bit >= 0; bit--) {
        int x = anc[aux][bit];
        if(x > 0 && lvl[nod] - lvl[x] < l && sp[nod] - sp[anc[x][0]] <= s) {
            aux = x;
        }
    }
    return aux;
}

void dfs1(int nod) {
    if(g[nod].empty()) {
        id[nod] = nod;
        ans++;
        return ;
    }
    int mn_lvl = MAXN + 1, which = -1;
    for(auto it : g[nod]) {
        dfs1(it);
        if(mn_lvl > lvl[get(id[it])]) {
            mn_lvl = lvl[get(id[it])];
            which = it;
        }
    }
    if(sp[id[which]] - sp[anc[nod][0]] > s || lvl[id[which]] - lvl[nod] == l) {
        id[nod] = nod;
        ans++;
    }
    else {
        id[nod] = id[which];
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n >> l >> s;
    int mx = 0;
    for(i = 1; i <= n; i++) {
        cin >> w[i];
        mx = max(mx, w[i]);
    }
    if(mx > s) {
        cout << -1;
        return 0;
    }
    for(i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);
    dfs1(1);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}