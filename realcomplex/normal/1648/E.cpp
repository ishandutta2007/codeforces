#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int LOG = 19;

struct edge{
    int u;
    int v;
    int w;
    bool operator< (const edge &q){
        return w < q.w;
    }
};

map<pii, bool> E;

void add_edge(int a, int b){
    if(a > b) swap(a, b);
    E[mp(a,b)]=true;
}

bool check_edge(int a, int b){
    if(a > b) swap(a, b);
    return E[mp(a, b)];
}

int p1[N];
int p2[N];

set<int> ele[N];
vector<int> ids[N];

int f1(int u){
    if(p1[u]==u) return u;
    return p1[u]=f1(p1[u]);
}

int f2(int u){
    if(p2[u]==u) return u;
    return p2[u]=f2(p2[u]);
}

vector<edge> graf;

void add_graf(int u, int v, int w){
    graf.push_back({u, v, w});
    u = f2(u);
    v = f2(v);
    // assume u != v
    if(ids[u].size() > ids[v].size()){
        swap(u, v);
    }
    p2[u] = v;
    for(auto x : ids[u]){
        ids[v].push_back(x);
    }
    ids[u].clear();
}

vector<pii> T[N];
int tin[N];
int tout[N];
int par[LOG][N];
int maxi[LOG][N];
int tt;

void dfs(int u, int pa, int las){
    tt++;
    tin[u]=tt;
    par[0][u]=pa;
    maxi[0][u]=las;
    for(int i = 1; i < LOG; i ++ ){
        par[i][u] = par[i-1][par[i-1][u]];
        maxi[i][u] = max(maxi[i-1][u], maxi[i-1][par[i-1][u]]);
    }
    for(auto x : T[u]){
        if(x.fi == pa) continue;
        dfs(x.fi, u, x.se);
    }
    tout[u]=tt;
}

bool is_anc(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int get(int u, int v){
    int res = 0;
    for(int i = LOG - 1; i >= 0 ; i -- ){
        if(!is_anc(par[i][u], v)){
            res = max(res, maxi[i][u]);
            u = par[i][u];
        }
    }
    for(int i = LOG - 1; i >= 0 ; i -- ){
        if(!is_anc(par[i][v], u)){
            res = max(res, maxi[i][v]);
            v = par[i][v];
        }
    }
    if(!is_anc(u, v)){
        res = max(res, maxi[0][u]);
    }
    if(!is_anc(v, u)){
        res = max(res, maxi[0][v]);
    }
    return res;
}

void solve(){
    tt = 0;
    int n, m;
    cin >> n >> m;
    vector<edge> fir(m);
    vector<edge> V;
    E.clear();
    for(int i = 0 ; i < m ; i ++ ){
        cin >> fir[i].u >> fir[i].v >> fir[i].w;
        add_edge(fir[i].u, fir[i].v);
    }
    V = fir;
    sort(fir.begin(), fir.end());
    for(int i = 1; i <= n; i ++ ) p1[i] = i;
    for(int i = 1; i <= n; i ++ ) p2[i] = i;
    for(int i = 1; i <= n; i ++ ) {
        ele[i].clear();
        ele[i].insert(i);
    }
    graf.clear();
    for(int i = 1; i <= n; i ++ ) {
        T[i].clear();
        ids[i].clear();
        ids[i].push_back(i);
    }
    int idx, id;
    int pp;
    int uu, vv;
    int idd;
    int sdd;
    for(auto &q : fir){
        q.u = f1(q.u);
        q.v = f1(q.v);
        if(q.u == q.v) continue; // no one fucking cares
        if(ele[q.u].size() > ele[q.v].size()) swap(q.u, q.v);
        vector<pii> unn;
        while(!ele[q.u].empty()){
            idd = *ele[q.u].begin();
            ele[q.u].erase(ele[q.u].begin());
            vector<int> uni;
            for(auto sdd : ele[q.v]){
                uu = vv = -1;
                for(auto x : ids[f2(idd)]){
                    for(auto y : ids[f2(sdd)]){
                        if(!check_edge(x, y)){
                            uu = x;
                            vv = y;
                            break;
                        }
                    }
                    if(uu != -1) break;
                }
                if(uu != -1){
                    uni.push_back(sdd);
                }
            }
            for(auto x : uni){
                ele[q.v].erase(x);
            }
            for(int i = 1; i < uni.size(); i ++ ){
                add_graf(uni[i-1], uni[i], q.w);
            }
            if(!uni.empty()){
                ele[q.v].insert(f2(uni[0]));
                unn.push_back(mp(idd, uni[0]));
            }
            else{
                unn.push_back(mp(idd, -1));
            }
        }
        for(auto v : unn){
            if(v.se == -1){
                ele[q.v].insert(v.fi);
            }
            else{
                add_graf(v.fi, v.se, q.w);
            }
        }
        ele[q.u].clear();
        p1[q.u] = q.v;
    }
    for(auto f : graf){
        T[f.u].push_back(mp(f.v, f.w));
        T[f.v].push_back(mp(f.u, f.w));
    }
    dfs(1, 1, 0);
    for(auto f : V){
        cout << get(f.u, f.v) << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}