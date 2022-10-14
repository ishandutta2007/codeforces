#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll N, bit[500005],M,arr[500005],loc;
pair<pair<ll,ll>,ll> graph[500005];
vector<ll> adj[500005];
bool visited[500005];
void update (ll n, ll val){
    if (n==0) return;
    while (n<=2*N){
        bit[n]+=val;
        n+= (n& (-n));
    }
    return;
}
ll query (ll n){
    ll ret=0;
    while (n>0){
        ret+=bit[n];
        n-= n&(-n);
    }
    return ret;
}
void dfs (ll n){
    graph[n].fi.fi=loc;
    graph[n].se=loc%2;
    visited[n]=true;
    for (ll i=0; i<adj[n].size(); i++){
        if (visited[adj[n][i]]) continue;

        // visited[n]=true;
        loc++;
        dfs(adj[n][i]);
    }
    loc++;
    graph[n].fi.se=loc;
    return;
}
int main (){
    cin>>N>>M;
    for (ll i=1; i<=N; i++) cin>>arr[i];
    for (ll i=1; i<N; i++){
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    loc=1;
    dfs(1);
    // N=2*N;
    for (ll i=1; i<=M; i++){
        ll qu; cin >> qu;
        if (qu==1){
            ll x,val; cin >> x >> val;
            if (graph[x].fi.fi%2!=0){
                update(graph[x].fi.se+1, val);
                update(graph[x].fi.fi, -val);
            } else{
                update(graph[x].fi.se+1, -val);
                update(graph[x].fi.fi, val);
            }
        } else{
            ll x, k=0; cin>>x;
            k=query(graph[x].fi.se);
            if (graph[x].se==1){
                k= arr[x]-k;
            } else{
                k= arr[x]+k;
            }
            cout << k << endl;
        }
        // cout << ">>>>>>>>>>>>>>>>>>>>>>>>\n";
        // for (ll i=1; i<=N; i++) cout << query(graph[i].fi.fi) << endl << graph[i].fi.fi << " " << graph[i].fi.se << endl;
        // cout << "<<<<<<<<<<<<<<<<<<<<<<<<\n";
    }
    
}

/*
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
 */