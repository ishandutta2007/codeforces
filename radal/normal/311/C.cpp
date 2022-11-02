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
const long long int N=1e4+20,mod = 1e9+7,inf=3e16,maxk = 1e5+20;
const long double eps = 0.0001;
ll n,m,h,k;
vector<pll> adj[N];
pair<pll,ll> b[10*N];
ll dp[N];
void dij(){
    memset(dp,63,sizeof dp);
    set<pll> s;
    dp[1] = 1;
    s.insert({1,1});
    while (!s.empty()){
        pll p = *(s.begin());
        s.erase(s.begin());
        for (pll u : adj[p.Y]){
            if (dp[u.X] > u.Y+p.X){
                s.erase({dp[u.X],u.X});
                dp[u.X] = u.Y+p.X;
                s.insert({dp[u.X],u.X});
            }
        }
    }
    return;
}
int main(){
 //   ios :: sync_with_stdio(false);
    memset(dp,63,sizeof dp);
    cin >> h >> n >> m >> k;
    rep(i,1,n+1){
        ll a,c;
        cin >> a >> c;
        b[i] = {{a,c},i};
    }
    set<pll> st;
    dp[1] = 1;
    rep(i,1,n+1) if (b[i].X.X%k == 1) st.insert({-b[i].X.Y,i});
    rep(i,0,m){
        int t;
        cin >> t;
        if (t == 1){
            st.clear();
            ll x;
            cin >> x;
            rep(i,0,k) adj[i].pb({(i+x)%k,x});
            dij();
            rep(i,1,n+1){
                if (dp[(b[i].X.X)%k] <= b[i].X.X) st.insert({-b[i].X.Y,i});
            }
        }
        if (t == 2){
            ll x,y;
            cin >> x >> y;
            if (st.find({-b[x].X.Y,x}) != st.end()){
                st.erase({-b[x].X.Y,x});
                b[x].X.Y -= y;
                st.insert({-b[x].X.Y,x});
            }
            else b[x].X.Y -= y;
        }
        if (t == 3){
            if (st.empty()){
                cout << 0 << endl;
                continue;
            }
            cout << -(*(st.begin())).X << endl;
            b[(*(st.begin())).Y].X.Y = 0;
            st.erase(st.begin());
        }
    }
    return 0;
}