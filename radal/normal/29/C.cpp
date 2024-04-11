#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll unsigned long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const int N=1e5+30;
pair<ll,ll> e[N];
map<ll,ll> hs;
vector<vector<ll> > adj;
vector<ll> ve;
void dfs(ll v,ll par){
    for (ll u: adj[v]){
        if (u!= par){
//            debug(u);
            cout << ve[u-1] << ' ';
            dfs(u,v);
        }
    }
}
int main(){
    int m;
    cin >> m;
    vector <ll> v;
    rep(i,0,m){
        cin >> e[i].X >> e[i].Y;
        v.pb(e[i].X);
        v.pb(e[i].Y);
    }
    sort(v.begin(),v.end());
    ve.pb(v[0]);
    rep(i,1,2*m){
        if (v[i] != v[i-1]){
            ve.pb(v[i]);
        }
    }
    rep (i,0,m+1){
    //    cout << ve[i] << ' ';
        hs[ve[i]] = i+1;
    }
    adj.resize(m+2);
    rep(i,0,m){
        adj[hs[e[i].X]].pb(hs[e[i].Y]);
        adj[hs[e[i].Y]].pb(hs[e[i].X]);
    }
    ll ind=0;
    rep (i,1,m+2){
        if (adj[i].size() == 1){
            ind = i;
            break;
        }
    }
    cout << ve[ind-1] << ' ';
    dfs(ind,-1);
}