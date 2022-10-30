#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=4e2+30,mod = 1e9+7,inf=1e9;
bool adj[N][N],co[N][N];
int visited[N];
int a[N],ans[N];
void dfs(int v, int c,int n){
    visited[v] = c;
   // debug(v);
    //debug(c);
    rep (i,1,n+1){
        if (adj[v][i] == 0) continue;
        if (!visited[i]){
            dfs(i,c,n);
          //  debug(i);
        }
    }
    
}
int main(){
    ll n,m,T=0;
    cin >> n >> m;
    rep(i,0,n){
        int x,y;
        cin >> x;
        if (!x) T++;
        rep(j,0,x){
            cin >> y;
            co[i][y] = 1;
            rep(k,0,i) if (co[k][y] == 1) {
                adj[i][k] = 1;
                adj[k][i] = 1;
    //            debug(i); debug(k);
            }
        }
    }
 //   debug(adj[0][2]);
    ll t=1;
    rep(i,0,n){
        if (!visited[i]){
 //           debug(i);
            dfs(i,t,n);
            t++;
        }
    }
  //  debug(adj[3][4]);
    cout << max(t-2,T);
}