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
int n;
int sz[nax];
int leavesSZ[nax];
int par[nax];

void dfs(int v, int p){
    par[v] = p;
    sz[v] = 0;
    leavesSZ[v] = 0;
    for(int x : adj[v]){
        if(x!=p){
            dfs(x, v);
            sz[v]++;
            if(sz[x] == 0) leavesSZ[v]++;
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++){
        int x,y ;cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1);
    int zrobione = 0;
    vector<int> q;
    for(int i=1;i<=n;i++){
        if(i != 1 && sz[i]){
            if(sz[i] == leavesSZ[i]){
                q.pb(i);
            }
        }
    }
    int wsk = 0;
    vector<int> xd;
    while(wsk < q.size()){
        int cur = q[wsk++];
        if(cur == 1 || sz[cur] == 0) continue;
        zrobione += (1 + sz[cur]);
        xd.pb(sz[cur]);
        int p = par[cur];
        sz[p]--;
        if(leavesSZ[p] == sz[p]){
            q.pb(p);
        }
        if(sz[p] == 0){
            int pp = par[p];
            leavesSZ[pp] += 1;
            if(leavesSZ[pp] == sz[pp]){
                q.pb(pp);
            }
        }
    }
    int ones = n - zrobione - 1;
    int cost = max(ones, 1);
    for(int x : xd){
        cost += x - 1;
    }
    cout<<cost<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}