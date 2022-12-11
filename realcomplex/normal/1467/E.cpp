#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int LOG = 20;
vector<int> T[N];

int tin[N];
int bad[N];
int tout[N];
int ti;
int par[LOG][N];
int vv[N];

void dfs(int u,int pp){
    ti ++ ;
    par[0][u]=pp;
    for(int i = 1; i < LOG; i ++ ){
        par[i][u]=par[i-1][par[i-1][u]];
    }
    tin[u]=ti;
    for(auto x : T[u]){
        if(x==pp)continue;
        dfs(x,u);
    }
    tout[u]=ti;
}

bool is_par(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

bool cmp(int u, int v){
    return tin[u] < tin[v];
}

int lca(int u, int v){
    if(is_par(u,v)) return u;
    for(int i = LOG - 1; i >= 0 ; i -- ){
        if(!is_par(par[i][u],v))
            u=par[i][u];
    }
    return par[0][u];
}


int main(){
    fastIO;
    int n;
    cin >> n;
    vector<pii> g(n);
    for(int i = 1; i <= n; i ++ ){
        cin >> g[i-1].fi;
        g[i-1].se=i;
    }
    sort(g.begin(), g.end());
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1,1);
    vector<int> nds;
    bool can;
    int cl, cr;
    int node;
    int mx;
    for(int i = 0 ; i < g.size(); i ++ ){
        nds.push_back(g[i].se);
        if(i + 1 == g.size() || g[i].fi != g[i + 1].fi){
            vector<int> cd = nds;
            for(auto x : nds) vv[x]=1;
            for(int j = 1; j < nds.size(); j ++ ){
                cd.push_back(lca(nds[j-1],nds[j]));
            }
            sort(cd.begin(), cd.end(), cmp);
            cd.resize(unique(cd.begin(), cd.end())-cd.begin());
            vector<int> qq = {cd[0]};
            for(int j = 1; j < cd.size(); j ++ ){
                node = cd[j];
                if(vv[node]){
                    cl = tin[node];
                    cr = tout[node];
                    bad[cl]++;
                    bad[cr+1]--;
                }
                while(!is_par(qq.back(), node))qq.pop_back();
                if(vv[qq.back()]){
                    mx = node;
                    for(int t = LOG - 1; t >= 0 ; t -- ){
                        if(!is_par(par[t][mx],qq.back()))
                            mx = par[t][mx];
                    }
                    cl = tin[mx];
                    cr = tout[mx];
                    bad[1]++;
                    bad[cl]--;
                    bad[cr+1]++;
                }
                qq.push_back(node);
            }
            for(auto x : nds) vv[x]=0;
            nds.clear();
        }
    }
    int cur = 0;
    int sol = 0;
    for(int i = 1; i <= n; i ++ ){
        cur += bad[i];
        if(cur == 0) sol ++ ;
    }
    cout << sol << "\n";
    return 0;
}