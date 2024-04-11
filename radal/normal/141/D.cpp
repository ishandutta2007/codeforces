#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=3e16,maxk = 1e5+20;
const long double eps = 0.0001;
ll n,l;
map<int,vector<pair<pll,int>>> adj;
map<int,ll> d;
map<int,pll> par;
set<int> vis;
pair<pll,pll> a[N];
pll x[3*N];
void dij(){
    vis.insert(0);
    d[0] = 0;
    set<pll> st;
    st.insert({0,0});
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        for(auto u : adj[p.Y]){
            if (u.X.X < 0) continue;
            if (vis.find(u.X.X) == vis.end() || d[u.X.X] > p.X+u.X.Y){
                if (vis.find(u.X.X) != vis.end()) st.erase({d[u.X.X],u.X.X});
                d[u.X.X] = p.X+u.X.Y;
                par[u.X.X] = {p.Y,u.Y};
                vis.insert(u.X.X);
                st.insert({d[u.X.X],u.X.X});
            }
        }
    }
    return;
}
int main(){
    cin >> n >> l;
    rep(i,1,n+1){
        cin >> a[i].X.X >> a[i].X.Y >> a[i].Y.X >> a[i].Y.Y;
        x[2*i] = {a[i].X.X+a[i].X.Y,0};
        x[2*i-1] = {a[i].X.X-a[i].Y.Y,i};
    }
    x[0] = {0,0};
    x[2*n+1]  = {l,0};
    sort(x,x+2*n+2);
    rep(i,0,2*n+2){
        if (x[i].X < 0) continue;
        if(x[i].Y) adj[a[x[i].Y].X.X-a[x[i].Y].Y.Y].pb({{a[x[i].Y].X.X+a[x[i].Y].X.Y,a[x[i].Y].Y.Y+a[x[i].Y].Y.X},x[i].Y});
        if (i){
            adj[x[i-1].X].pb({{x[i].X,x[i].X-x[i-1].X},0});
            adj[x[i].X].pb({{x[i-1].X,x[i].X-x[i-1].X},0});
        }
    }
 //   debug(x[5].X);
    dij();
    cout << d[l] << endl;
    vector<int> ve;
    ll v = l;
    while (v){
        if (par[v].Y) ve.pb(par[v].Y);
        v = par[v].X;
    }
    reverse(ve.begin(),ve.end());
    cout << ve.size() << endl;
    for (int u : ve) cout << u << ' ';
    return 0;
}