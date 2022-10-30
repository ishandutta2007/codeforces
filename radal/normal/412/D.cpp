#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;
typedef pair<int,int> pll;
const ll N = 3e4+30,mod=1e9+7;
vector <int> adj[N],ans;
bool vis[N];
bool dfs(int v){
    vis[v] = 1;
   // ans.pb(v);
    /*bool f=1;
    if (!ans.empty()) {
        for(int u : adj[ans.back()]){
            if (u == v) {
                f = 0;
                break;
            }
        }
    }
    if (f) {
        ans.pb(v);
        debug(v);
    }
    else{
        f = 1;
        for(int u : adj[v]) if (u == ans.front()){
            f = 0;
            break;
        }
     //   if (f) {
            ans.insert(ans.begin(),v);
       // }
        //else return 0;
    }*/
    for (int u : adj[v]){
        if (!vis[u]){
            //ans.pb(u);
          //  if (!dfs(u)) return 0;
           dfs(u);
        }
    }
    ans.pb(v);
    return 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    //rep(i,1,n+1) adj[0].pb(i);
    rep (i,1,n+1){
        if (!vis[i]){
            dfs(i);
    //        reverse(ans.begin(),ans.end());
        }
     //   ans.pb(i);
    }
    rep (i,0,n) cout << ans[i] << ' ';
}