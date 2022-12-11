#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1050;

struct pos{
    int val;
    int ii;
    int jj;
    bool operator< (const pos &q) const {
        return val < q.val;
    }
};
int soln[N][N];

const int M = 4 * N * N + 4 * N;
int g[N][N][4];
vector<pii> T[M];
int pp;
int cur;
int cum;
int ccm;

bool outp;

void trav(int node, int mx){
    int nex;
    if(outp){
        cout << mx << " # ";
    }
    ccm = (ccm + (cur - mx));
    for(auto x : T[node]){
        nex = max(mx, x.se);
        trav(x.fi, nex);
    }
}

int par[M];
int sum[M];
int cnt[M];

int fin(int u){
    if(par[u]==u) return u;
    return par[u]=fin(par[u]);
}


void add_edge(int uu, int vv, int w){
        // vv -> uu
    if(fin(uu) == vv) return; // dont care
    T[vv].push_back(mp(uu, w));
    uu = fin(uu);
    sum[uu] = (sum[vv] + w * 1ll * cnt[uu]) % 2;
    cnt[uu] += cnt[vv];
    par[vv] = uu;
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pos> pip;
    int x;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cin >> x;
            pip.push_back({x, i, j});
        }
    }
    for(int i = 0 ; i <= n + 1; i ++ ){
        for(int j = 0; j <= m + 1; j ++ ){
            for(int t = 0; t < 4; t ++ ){
                pp ++ ;
                g[i][j][t] = pp;
            }
        }
    }
    sort(pip.begin(), pip.end());
    int ip, jp;
    for(int i = 1; i <= pp; i ++ ){
        par[i]=i;
        cnt[i]=1;
        sum[i]=1;
    }
    int go;
    for(auto pp : pip){
        ip = pp.ii;
        jp = pp.jj;
        cur = pp.val;
        cum = 0;
        for(int p = 0 ; p < 4; p ++ ){
            go = fin(g[ip][jp][p]);
            cum += ((cur * 1ll * cnt[go]) - sum[go]) % 2;
            cum %= 2;
        }
        soln[ip][jp] = cum;
        if(cum == 0){
            add_edge(g[ip][jp][0], g[ip+1][jp][0], cur);
            add_edge(g[ip][jp][2], g[ip-1][jp][2], cur);
            add_edge(g[ip][jp][1], g[ip][jp-1][1], cur);
            add_edge(g[ip][jp][3], g[ip][jp+1][3], cur);
        }
        else{
            add_edge(g[ip][jp][0], g[ip][jp-1][1], cur);
            add_edge(g[ip][jp][1], g[ip-1][jp][2], cur);
            add_edge(g[ip][jp][2], g[ip][jp+1][3], cur);
            add_edge(g[ip][jp][3], g[ip+1][jp][0], cur);
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cout << soln[i][j];
        }
        cout << "\n";
    }
    return 0;
}