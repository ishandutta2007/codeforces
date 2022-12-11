#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;

vector<int> T[N];
vector<int> G[N];
int u[N], v[N];
int bit[N];
int col[N];
int idc[N];
int idx;
bool bad;
bool bb[N];

void dfs(int u){
    idc[u]=idx;
    for(auto x : T[u]){
        if(col[x] == col[u]){
            if(bit[x] == bit[u]){
                bad=true;
            }
            else if(bit[x] == -1){
                bit[x] = bit[u]^1;
                dfs(x);
            }
        }
    }
}

struct Edge{
    int nex_col;
    int vi;
    int vj;
    int cond;
    bool operator< (const Edge &E) const {
        return nex_col < E.nex_col;
    }
};

vector<Edge> ni[N];

vector<pii> F[N];
int puy[N];

bool add;

void dfs1(int u){
    for(auto q : F[u]){
        if(puy[q.fi] == -1){
            puy[q.fi]=(puy[u]^q.se);
            dfs1(q.fi);
        }
        else{
            if((puy[q.fi]^puy[u]) != q.se)
                add=false;
        }
    }
}

int main(){
    fastIO;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> col[i];
        G[col[i]].push_back(i);
        bit[i]=-1;
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i];
        T[u[i]].push_back(v[i]);
        T[v[i]].push_back(u[i]);
    }
    for(int i = 1; i <= n; i ++ ){
        if(bit[i] == -1){
            idx ++ ;
            bit[i]=0;
            bad=false;
            dfs(i);
            if(bad){
                bb[col[i]]=true;
            }
        }
    }
    int valid = 0;
    for(int i = 1; i <= k ; i ++ ){
        if(!bb[i]) valid ++ ;
    }
    for(int i = 1; i <= m; i ++ ){
        if(bb[col[u[i]]] || bb[col[v[i]]]) continue;
        if(col[u[i]] == col[v[i]]) continue;
        if(col[u[i]] > col[v[i]]) swap(u[i], v[i]);
        if(bit[u[i]] == bit[v[i]]){
            ni[col[u[i]]].push_back({col[v[i]], idc[u[i]], idc[v[i]], 1});
        }
        else{
            ni[col[u[i]]].push_back({col[v[i]], idc[u[i]], idc[v[i]], 0});
        }
    }
    ll sol = valid * 1ll * (valid - 1) / 2ll;
    for(int i = 1; i <= k ; i ++ ){
        sort(ni[i].begin(), ni[i].end());
        while(!ni[i].empty()){
            vector<int> chk;
            int cur = ni[i].back().nex_col;
            while(!ni[i].empty() && ni[i].back().nex_col == cur){
                F[ni[i].back().vi].push_back(mp(ni[i].back().vj, ni[i].back().cond));
                F[ni[i].back().vj].push_back(mp(ni[i].back().vi, ni[i].back().cond));
                chk.push_back(ni[i].back().vi);
                chk.push_back(ni[i].back().vj);
                ni[i].pop_back();
            }
            add = true;
            for(auto q : chk){
                puy[q]=-1;
            }
            for(auto q : chk){
                if(puy[q] == -1){
                    puy[q]=0;
                    dfs1(q);
                }
            }
            sol -= !add;
            for(auto q : chk){
                F[q].clear();
            }
        }
    }
    cout << sol << "\n";
    return 0;
}