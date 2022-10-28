#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
typedef pair<int,ii> iii;
vector<vector<iii>> g;
int ans[200001];
int marked[200001];
int sum[200001];
int lol[200001];
int main()
{
    boost;
    int n,m;cin>>n>>m;g.resize(n);
    FOR(i,1,m){
      int x,y,z;cin>>x>>y>>z;--x,--y;
      g[x].pb({y,{z,i}});
      g[y].pb({x,{z,-i}});
      sum[x]+=z;
      sum[y]+=z;
      if(x==n-1)ans[i]=1,marked[i]=1;
    }
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
      int now = q.front();
      q.pop();
      for(auto it:g[now]){
         if(it.F==n-1)continue;
         if(!marked[abs(it.S.S)])marked[abs(it.S.S)]=1,ans[abs(it.S.S)]=it.S.S>0?0:1;
         else continue;
         if(((lol[it.F]+=it.S.F)==sum[it.F]/2))
         q.push(it.F);
      }
    }
    FOR(i,1,m)cout<<ans[i]<<"\n";
   return 0;
}