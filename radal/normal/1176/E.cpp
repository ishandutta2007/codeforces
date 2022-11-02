#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30;
bool visited[N];
vector < vector<ll> >adj,adj2;
vector <pair<ll,ll> > tree;
vector <ll> red,blue;
void dfs(ll v){
    visited[v] = 1;
    for (int u : adj[v]){
        if (!visited[u]){
            tree.pb(mp(v,u));
            dfs(u);
        }
    }
}
void dfs2(ll v,ll par,bool color){
    if (!color) blue.pb(v);
    else red.pb(v);
    for (int u : adj2[v]){
        if (u != par){
            dfs2(u,v,!color);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0);
	cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        rep(i,0,m){
            ll x,y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        rep(i,0,n) visited[i] = 0;
        tree.clear();
        dfs(0);
        adj2.clear();
        adj2.resize(n);
        rep (i,0,n-1){
            adj2[tree[i].X].pb(tree[i].Y);
            adj2[tree[i].Y].pb(tree[i].X);
        }
        blue.clear();
        red.clear();
        dfs2(0,-1,0);
        if (blue.size()<= n/2){
            cout << blue.size() << endl;
            for (int u : blue){
                cout << u+1 << ' ';
            }
            cout << endl;
        }
        else{
            cout << red.size() << endl;
            for (int u : red){
                cout << u+1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}