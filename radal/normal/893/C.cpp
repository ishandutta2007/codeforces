#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e5+10;
vector<vector<ll> > adj;
ll c[N];
pair <ll,ll> visited[N];
void dfs(ll v,ll t){
    visited[v].X = t;
    for (ll u : adj[v]){
        if (visited[u].X == 0){
            visited[u].X = t;
            dfs(u,t);
        }
    }
}
int main(){
    ll n,m;
    cin >> n >> m;
    rep (i,0,n){
        cin >> c[i];
        visited[i].Y = i;
        visited[i].X = 0;
    }
    adj.resize(n);
    rep (i,0,m){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll C=1;
    rep (i,0,n){
        if (visited[i].X) continue;
        
        dfs(i,C);
        C++;
    }
    ll ans = 0;
    sort(visited,visited+n);
    rep (i,0,n){
        ll cnt=0;
       // if (i == n-1 || visited[i].X == visited[i+1].X){
            cnt = c[visited[i].Y];
            i++;
      //  }
        while (i < n && visited[i].X == visited[i-1].X){
            cnt = min(cnt,c[visited[i].Y]);
            i++;
        }
        ans += cnt;
        i--;
    }
    cout << ans;
    return 0;
}