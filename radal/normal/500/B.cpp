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
string adj[N];
pair<int,int> visited[N];
int a[N],ans[N];
void dfs(int v, int c,int n){
    visited[v].X = c;
    rep (i,0,n){
        if (adj[v][i] == '0') continue;
        if (!visited[i].X){
            dfs(i,c,n);
 //           debug(i);
        }
    }
    
}
int main(){
    int n;
    cin >> n;
    rep (i,0,n) {
        cin >> a[i];
        visited[i].Y = i;
    }
    rep(i,0,n){
        cin >> adj[i];
    }
    ll t=1;
    rep(i,0,n){
        if (!visited[i].X){
            dfs(i,t,n);
            t++;
        }
    }
    //debug(adj[0][4]);
    //rep(i,0,n) cout << visited[i].X << ' ' ;
    sort(visited,visited+n);
    vector <int> ve,ind;
    rep(i,0,n){
  //      cout << visited[i].Y << ' ';
        while (i < n-1 && visited[i].X == visited[i+1].X){
            ve.pb(a[visited[i].Y]);
            ind.pb(visited[i].Y);
            i++;
        }
        ve.pb(a[visited[i].Y]);
        ind.pb(visited[i].Y);
        sort(ve.begin(),ve.end());
        int s = ind.size();
        rep(j,0,s){
            ans[ind[j]] = ve[j];
        }
        ve.clear();
        ind.clear();
    }
//    cout << endl;
    rep(i,0,n) cout << ans[i] << ' '; 
 //   cout << 0;
}