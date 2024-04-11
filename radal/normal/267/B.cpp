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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int n,m;
vector <pair<int,pair<int,bool> > > adj[N];
bool visited[6*N];
vector <pair<int,bool> > ve;
vector<pll> me;
void dfs(int v,int ind,bool b){
    while (!adj[v].empty()){
        auto u = adj[v].back();
        adj[v].pop_back();
        if (!visited[u.Y.X]){
            visited[u.Y.X] = 1;
            dfs(u.X,u.Y.X,u.Y.Y);
        }
    }
    if  (ind != -1) ve.pb({ind,b});
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    me.resize(n);
    rep(i,0,n){
        cin >> me[i].X >> me[i].Y;
        adj[me[i].X].pb({me[i].Y,{i+1,0}});
        adj[me[i].Y].pb({me[i].X,{i+1,1}});
    }
    int cnt = 0,sc = -1;
    rep(i,0,7){
        if (adj[i].size()%2){
            cnt++;
            sc = i;
        }
        if (!cnt && !adj[i].empty()){
            sc = i;
        }
    }
    if (cnt != 2 && cnt){
        cout << "No solution" << endl;
        return 0;
    }
    dfs(sc,-1,0);
   // reverse(ve.begin(),ve.end());
    rep(i,1,n+1){
        if (!visited[i]){
            cout << "No solution";
            return 0;
        }
    }
    for (auto u : ve){
        cout << u.X << ' ';
        if (!u.Y) cout << '-' << endl;
        else cout << '+' << endl;
        //    if (!u.Y) cout << me[u.X-1].X << ' ' << me[u.X-1].Y << endl;
          //  else cout << me[u.X-1].Y << ' ' << me[u.X-1].X << endl;
    }
    return 0;   
}