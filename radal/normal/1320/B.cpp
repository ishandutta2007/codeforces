#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,mod = 998244353;
ll ans=0;
vector <vector<int> > adj;
ll dist[N],path[N],visited[N],cnt[N];
void bfs(int v){
    visited[v] = 1;
    queue <pair<ll,ll>> q;
    ll d = 0;
    q.push(mp(v,0));
    while (!q.empty()){
        for (int u : adj[q.front().X]){
            if (!visited[u]){
                q.push(mp(u,q.front().Y+1));
                dist[u] = q.front().Y+1;
       //         debug(u); debug(dist[u]);
                visited[u] = 1;
            }
        }
        q.pop();
    }
}
int main(){
    ll n,m;
    cin >> n >> m;
    adj.resize(n);
    rep (i,0,m){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[y].pb(x);
    }
    ll k;
    cin >> k;
    rep (i,0,k) cin >> path[i];
    bfs(path[k-1]-1);
 //   rep (i,0,n){
    //    cout << dist[i] << ' ';
   // }
  //  cout << endl;
    rep (i,0,n){
        for (int j : adj[i]){
            if (dist[j] == dist[i]+1) cnt[j]++;
        }
    }
    ll Min = 0,Max=0;
    path[0]--;
    path[k-1]--;
    rep (i,1,k-1){
        path[i]--;
        if (dist[path[i]] == dist[path[i-1]] -1){
            if (cnt[path[i-1]] > 1) Max++;
        }
        else{
            Min++;
            Max++;
        }
    }
    cout << Min << ' ' << Max;
}