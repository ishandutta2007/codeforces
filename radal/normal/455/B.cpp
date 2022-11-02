#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
map<string,int> mp;
string s[N];
vector<int> adj[N];
bool ma[N],vis[N],r[N],ma2[N],dp[N];
void dfs(int v){
    vis[v] = 1;
    for(int u : adj[v]){
        if (!vis[u]) dfs(u);
        if (!ma[u]) ma[v] = 1;
    }
}
void dfs2(int v){
    r[v] = 1;
    ma2[v] = 1;
    for (int u : adj[v]){
        if(!r[u]) dfs2(u);
        if (ma2[u]) ma2[v] = 0;
    }
    if (adj[v].empty()) ma2[v] = 0;
}
int main(){
    int n,k;
    cin >> n >> k;
    k &= 1;
    mp[""] = 1;
    int cnt = 1;
    rep(i,0,n){
        cin >> s[i];
        int m = s[i].size();
        string t="";
        rep(j,0,m){
            if (mp.find(t+s[i][j]) == mp.end()){
                cnt++;
                mp[t+s[i][j]] = cnt;
            }
            adj[mp[t]].pb(mp[t+s[i][j]]);
            t+=s[i][j];
        }
    }
    dfs(1);
    dfs2(1);
    if (ma[1]){
        if (ma2[1]){
            if (k) cout <<"First";
            else cout << "Second";
        }
        else cout << "First";
    }
    else
        cout << "Second";
    dp[1] = ma[1];
    return 0;
}