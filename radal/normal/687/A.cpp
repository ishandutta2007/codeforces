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
pair <bool,bool> visited[N];
bool f=1;
vector <ll> r,b;
void dfs(ll v){
    visited[v].X = 1;
    for (ll u : adj[v]){
        if (!visited[u].X){
            visited[u].X = 1;
            visited[u].Y = !visited[v].Y;
            if (visited[v].Y){
                r.pb(u);
            }
            else{
                b.pb(u);
            }
            dfs(u);
        }
        else{
            if (visited[u].Y == visited[v].Y){
                f = 0;
                return;
            }
        }
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
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i,0,n){
        if (!visited[i].X){
            r.pb(i);
            dfs(i);
        }
    }
    if (!f){
        cout << -1;
        return 0;
    }
    cout << r.size() << endl;
    for (ll u : r){
        cout << u+1 << ' ';
    }
    cout << endl << b.size() << endl;
    for (ll u : b){
        cout << u+1 << ' ';
    }
    return 0;
}