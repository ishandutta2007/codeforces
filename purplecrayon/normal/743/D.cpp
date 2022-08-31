#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define mod (1000000007)
#define pii pair<int,int>
#define f first
#define s second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
typedef long long int ll;
#define ld long double
const int N = 2e5+40;
const int M = 10005;

ll a[N+2];
ll mx[N+2];
ll sub[N+2];
ll ans = -1e18;
vector < vector < int > > adj(N+3);
vector<bool> visited(N+2,0);

void dfs(int v) {
    visited[v] = true;
    ll mx1 = -1e18,mx2 = -1e18;
    sub[v] = a[v];
    ll mxu = -1e18;
    for (int u : adj[v]) {
        if (!visited[u]){
            dfs(u);
            sub[v]+=sub[u];
            if(mx[u]>=mx1){
              mx2 = mx1;
              mx1 = mx[u];
            }
            else if(mx[u]>mx2){
              mx2 = mx[u];
            }
            mxu = max(mxu,mx[u]);
        }
        mx[v] = sub[v];
        mx[v] = max(mx[v], mxu);
    }
    
    if(mx1!=-1e18 && mx2!=-1e18) ans = max(ans,mx1+mx2);
}



void solve(){
    int n;
    cin>>n;
    forf(i,1,n+1){
      cin>>a[i];
    }
    forf(i,1,n){
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dfs(1);
    if(ans==-1e18){
      cout<<"Impossible"<<'\n';
    }
    else cout<<ans<<'\n';
}
 
 
int main(){
 	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T=1;
  //cin >> T;
  //comp();
	while(T--){
		solve();
  }
}