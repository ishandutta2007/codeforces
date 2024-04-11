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
const long long int N=1e6+30,mod = 1e9+7;
vector <vector<pair<ll,ll> > > adj;
vector <ll> d,p;
void dijkstra(ll s,ll n){
    d[s] = 0;
    set <pair<ll,ll> > q;
    q.insert(mp(0,s));
    while (!q.empty()){
        int v = q.begin()->Y;
        q.erase(q.begin());
        if (d[v] == 1e18) break;
        for (pair<ll,ll> edge : adj[v]){
            if (d[edge.X] > d[v] + edge.Y){
                p[edge.X] = v;
                d[edge.X] = d[v] + edge.Y;
                q.insert(mp(d[edge.X],edge.X));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m;
    cin >> n >> m;
    adj.resize(n);
    rep(i,0,m){
        ll x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    d.assign(n,1e18);
    p.assign(n,-1);
    dijkstra(0,n);
    if (d[n-1] == 1e18){
        cout << -1;
        return 0;
    }
    ll v = n-1;
    vector <ll> path;
    while (v != 0){
        path.pb(v+1);
        v = p[v];
    }
    path.pb(v+1);
    reverse(path.begin(),path.end());
    for (ll u : path) cout << u << ' ';

}