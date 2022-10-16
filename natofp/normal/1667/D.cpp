#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
vector<int> adj[nax];
vector<int> g[nax];
int n;
bool wa;
map<pii, int> edges;
int deg[nax];

int dfs(int v, int p){
    int cp = 0;
    int cnp = 0;
    vector<int> par, npar;
    for(int x : adj[v]){
        if(x != p){
            int w = dfs(x, v);
            if(w & 1){
                cnp += 1;
                pii edge = mp(x, v);
                if(x > v) edge = mp(v, x);
                npar.pb(edges[edge]);
            }
            else{
                cp += 1;
                pii edge = mp(x, v);
                if(x > v) edge = mp(v, x);
                par.pb(edges[edge]);
            }
        }
    }
    if(v == 1){
        if(cp != cnp && cp + 1 != cnp) wa = true;
        if(!wa){
            vector<int> ord;
            int sz = par.size() + npar.size();
            if(sz & 1){
                for(int i=0;i<sz;i++){
                    if(i & 1) ord.pb(par[i / 2]);
                    else ord.pb(npar[i / 2]);
                }
            }
            else{
                for(int i=0;i<sz;i++){
                    if(i & 1) ord.pb(npar[i / 2]);
                    else ord.pb(par[i / 2]);
                }
            }
            for(int i=1;i<ord.size();i++){
                int from = ord[i - 1];
                int to = ord[i];
                g[from].pb(to);
                deg[to]++;
            }
        }
        return 0;
    }
    else{
        int result = 0;
        if((cp + cnp) & 1){
            int take = 0;
            if(cnp < (cp + cnp + 1) / 2) take = 1;
            if(cp + (take == 0) != cnp + (take == 1)) wa = true;
            result = take;
        }
        else{
            int take = 0;
            if(cp >= cnp) take = 1;
            if(cp + (take == 0) + 1 != cnp + (take == 1)) wa = true;
            result = take;
        }
        pii edge = mp(v, p);
        if(v > p) edge = mp(p, v);
        if(result == 0) par.pb(edges[edge]);
        else npar.pb(edges[edge]);
        if(!wa){
            vector<int> ord;
            int sz = par.size() + npar.size();
            if(sz & 1){
                for(int i=0;i<sz;i++){
                    if(i & 1) ord.pb(par[i / 2]);
                    else ord.pb(npar[i / 2]);
                }
            }
            else{
                for(int i=0;i<sz;i++){
                    if(i & 1) ord.pb(npar[i / 2]);
                    else ord.pb(par[i / 2]);
                }
            }
            for(int i=1;i<ord.size();i++){
                int from = ord[i - 1];
                int to = ord[i];
                g[from].pb(to);
                deg[to]++;
            }
        }
        return result;
    }
}

void solve(){
    cin >> n;
    edges.clear();
    for(int i=1;i<=n;i++){
        adj[i].clear();
        g[i].clear();
        deg[i] = 0;
    }
    vector<pii> all;
    all.pb(mp(0, 0));
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        if(x > y) swap(x, y);
        edges[mp(x, y)] = i;
        all.pb(mp(x, y));
    }
    wa = false;
    dfs(1, 1);
    if(wa) cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        vector<int> Q;
        for(int i=1;i<n;i++){
            if(deg[i] == 0) Q.pb(i);
        }
        int wsk = 0;
        while(wsk < Q.size()){
            int cur = Q[wsk++];
            for(int x : g[cur]){
                deg[x] -= 1;
                if(deg[x] == 0) Q.pb(x);
            }
        }
        for(int x : Q){
            cout << all[x].st << " " << all[x].nd << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}