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

const int nax = 3e5 + 5;
vector<int> G[nax];
multiset<int> adj[nax];
int n, m;
bool vis[nax];
int dp[nax];
int par[nax];
int deg[nax];

multiset<int> graf[nax];

void dfs(int v, int p, int lv){
    if(p != 0){
        adj[v].insert(p);
        adj[p].insert(v);
    }
    dp[v] = lv;
    par[v] = p;
    vis[v] = true;
    for(int x : G[v]){
        if(!vis[x]) dfs(x, v, lv + 1);
    }
}

/*
procedure FindEulerPath(V)
  1. iterate through all the edges outgoing from vertex V;
       remove this edge from the graph,
       and call FindEulerPath from the second end of this edge;
  2. add vertex V to the answer.
  */

vector<int> cur;

void go(int v){
    while(graf[v].size()){
        int to = (*graf[v].begin());
        graf[v].erase(graf[v].find(to));
        graf[to].erase(graf[to].find(v));
        go(to);
    }
    cur.pb(v);
}

map<pii, vector<int>> poz;

vector<int> ans[nax];

vector<int> getPath(int from, int to){
    vector<int> one, two;
    one.pb(from);
    two.pb(to);
    while(from != to){
        if(dp[from] > dp[to]){
            from = par[from];
            one.pb(from);
        }
        else{
            to = par[to];
            two.pb(to);
        }
    }
    vector<int> es;
    for(int x : one) es.pb(x);
    for(int i=(int)two.size()-2;i>=0;i--){
        es.pb(two[i]);
    }
    return es;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1, 0, 0);
    int q; cin >> q;
    vector<pii> xd;
    int cnt = 0;
    for(int i=1;i<=q;i++){
        int x,y; cin >> x >> y;
        xd.pb(mp(x, y));
        deg[x] += 1;
        deg[y] += 1;
        graf[x].insert(y);
        graf[y].insert(x);
        poz[mp(x, y)].pb(i);
    }
    for(int i=1;i<=n;i++) cnt += (deg[i] % 2 == 1);
    int need = cnt / 2;
    if(need != 0){
        cout << "NO" << "\n";
        cout << cnt / 2 << "\n";
        return;
    }

    for(int i=1;i<=n;i++){
        cur.clear();
        go(i);
        for(int i=1;i<cur.size();i++){
            int s1 = cur[i - 1];
            int s2 = cur[i];
            if(poz[mp(s1, s2)].size()){
                int id = poz[mp(s1, s2)].back();
                poz[mp(s1, s2)].pop_back();
                vector<int> cur = getPath(s1, s2);
                ans[id] = cur;
            }
            else{
                swap(s1, s2);
                int id = poz[mp(s1, s2)].back();
                poz[mp(s1, s2)].pop_back();
                vector<int> cur = getPath(s1, s2);
                ans[id] = cur;
            }
        }
    }
    cout << "YES" << "\n";
    for(int i=1;i<=q;i++){
        cout << ans[i].size() << "\n";
        for(int x : ans[i]) cout << x << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}