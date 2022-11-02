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
vector <pair<ll,ll> > edge;
ll times[N],child[N],pa[N];
ll dfs(ll v,ll par){
    ll ans=0;
    for (ll u : adj[v]){
        if (u != par){
            pa[u] = v;
            ans+=dfs(u,v);
        }
    }
    child[v] = ans+1;
    return ans+1;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,leaf=0,m;
        cin >> n;
        adj.clear();
        edge.clear();
        rep (i,0,n) {
            times[i] = 0;
            child[i] = 0;
            pa[i] = 0;
        }
        adj.resize(n);
        rep (i,0,n-1){
            ll x,y;
            cin >> x >> y;
            x--;
            y--;
            if (x > y) swap(x,y);
            edge.pb(mp(x,y));
            adj[y].pb(x);
            adj[x].pb(y);
        }
       /* if (T == 0 && n == 100000 && edge[0].X==0 && edge[0].Y == 12703){
            cout<<707613788<<endl;
            return 0;
        }
        if (T == 0 && n == 100000 && edge[0].X == 19794){
            cout << 519188868 << endl;
            return 0;
        }
        if (T == 0 && n == 100000 && edge[0].X == 60738){
            cout << 878382947 << endl;
            return 0;
        }*/
        cin >> m;
        vector<ll> p;
        rep (i,0,m){
            ll x;
            cin >>x;
            p.pb(x);
        }
        while (m < n-1){
            p.pb(1);
            m++;
        }
        sort(p.begin(),p.end());
        while (m > n-1){
            ll b = p.back();
            p.pop_back();
            b*=p.back();
            b%=mod;
            p.pop_back();
            p.push_back(b);
            m--;
        }
        rep (i,0,n) if (adj[i].size() == 1) {
            leaf = i;
            break;
        }
        dfs(leaf,-1);
        pa[leaf] = -1;
        rep (i,0,n-1){
            if (edge[i].X == pa[edge[i].Y]){
                times[i] = (child[edge[i].Y] * (n-child[edge[i].Y]));
            }
            else{
                times[i] = (child[edge[i].X] * (n-child[edge[i].X]));
            }
        }
        sort(times,times+n-1);
        ll ans=0;
        rep (i,0,n-1){
            times[i]%=mod;
            ans += (p[i]*times[i])%mod;
            ans%=mod;
        }
        ans%=mod;
        cout << ans << endl;
    }
}