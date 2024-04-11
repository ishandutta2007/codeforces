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
vector <vector<ll> > adj;
vector<ll> par,s,val;
ll ans=0;
void bfs(ll v){
    queue <pair<ll,ll> > q;
    q.push(mp(v,0));
    while (!q.empty()){
        if (q.front().Y%2){
            ll mi=1e12;
            for (ll u : adj[q.front().X]){
                if (u != par[q.front().X]){
                    mi = min(mi,s[u]-s[par[q.front().X]]);
                }
            }
            if (mi == 1e12) val[q.front().X] = 0;
            else val[q.front().X] = mi;

        }
        else{
            if (q.front().X != 0){
                val[q.front().X] = s[q.front().X] - s[par[par[q.front().X]]]-val[par[q.front().X]];
            }
        }
        for (ll u : adj[q.front().X]){
            if (u != par[q.front().X]){
                q.push(mp(u,q.front().Y+1));
            }
        }
        q.pop();
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin >> n;
    par.resize(n);
    s.resize(n);
    adj.resize(n);
    val.resize(n);
    rep(i,1,n){
        cin >> par[i];
        par[i]--;
        adj[i].pb(par[i]);
        adj[par[i]].pb(i);
    }
    par[0] = -1;
    rep (i,0,n){
        cin >> s[i];
    }
    ll f=0;
    rep (i,1,n){
        if (s[i] == -1) continue;
        if (par[par[i]] != -1 && s[par[par[i]]] > s[i]) f = 1;
    }
    if (f){
        cout << -1;
        return 0;
    }   
    val[0] = s[0];
    bfs(0);
    ll ans=0;
    rep (i,0,n) {
    //    debug(i); debug(val[i]);
        ans += val[i];
    }
    cout << ans << endl;

}