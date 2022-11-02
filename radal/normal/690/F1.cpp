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
const long long int N=1e6+30,mod = 998244353;
ll ans=0;
vector <vector<int> > adj;
void dfs(int v,int par, int len){
    if (len > 1) return;
    for (int u : adj[v]){
        if (u != par){
            if (len == 1) ans++;
            dfs(u,v,len+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    adj.resize(n);
    rep (i,0,n-1){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i,0,n) dfs(i,-1,0);
    cout << ans/2;
    
}