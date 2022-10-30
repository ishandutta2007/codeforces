#include <iostream>
#include <vector>
#include <algorithm>
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
const int N=2e3+30;
vector<vector<int> > adj;
vector <bool> cat,visited;
vector <int> ve;
int ans,m;
void check(vector <int> ve){
    int t=0;
    int cnt=0,s=ve.size();
    rep (i,0,s){
      //  cout << ve[i]+1 << " ";
        if (cat[ve[i]]) t++;
        else{
            cnt = max(t,cnt);
            t=0;
        }
    }
    cnt = max(t,cnt);
    if (cnt <= m) ans++;
    //cout << endl;
}
void dfs(int v){
    visited[v] = 1;
    ll sz = adj[v].size();
    rep(u,0,sz){
        if (!visited[adj[v][u]]){
         //   cout << adj[v][u]+1 << " ";
            ve.pb(adj[v][u]);
            dfs(adj[v][u]);
       //     cout << endl;
            if (adj[ve.back()].size() == 1){
                check(ve);
            }
            ve.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n >> m;
    ans=0;
    cat.resize(n);
    visited.resize(n);
    adj.resize(n);
    rep (i,0,n) {
        bool f;
        cin >> f;
        cat[i] = f;
    }
    rep (i,0,n-1){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    //cout << endl;
    ve.pb(0);
    dfs(0);
   // if (!ve.empty()){
       // path.pb(ve);
    cout << ans;
    return 0;
}