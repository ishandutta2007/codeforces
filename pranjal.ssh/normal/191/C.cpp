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
#define rz resize
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
// inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
// 0 based indexing
vi p,l,sub;
int s[20][100001];
vi lg2;vvii g;
int mark[100001];
int ans[100001];
void dfs(int i)
{
   tr(g[i],it)
   {
      if(p[i]==it->F)continue;
      p[it->F]=i;
      l[it->F]=l[i]+1;
      dfs(it->F);
   }
}
void pre(int n)
{
   l.rz(n);p.rz(n),sub.rz(n);
   lg2.rz(n+1);
   l[0]=0;  p[0]=-1;
   FOR(i,2,n)lg2[i]=lg2[i-1]+((i&(i-1))==0);
   dfs(0);
   FOR(i,0,n-1)
   for(int j=0;(1<<j)<n;++j)  s[j][i]=-1; 
   FOR(i,0,n-1)s[0][i]=p[i];  
   for(int j=1;(1<<j)<n;++j)
      FOR(i,0,n-1)if(s[j-1][i]!=-1)s[j][i]=s[j-1][s[j-1][i]];
   
}
inline void lca(int u, int v)
{  
   if(l[u]<l[v])swap(u,v); 
   int LOG=lg2[l[u]];
   int U=u,V=v;

   NFOR(i,LOG,0)
   if((l[u]-(1<<i))>=l[v])
   u=s[i][u];
   
   if(u==v){mark[U]++,mark[V]--;return;}
   
   NFOR(i,LOG,0)
   if(s[i][u]!=-1 and s[i][u]!=s[i][v])
   u=s[i][u],v=s[i][v];
   mark[U]++,mark[V]++;mark[p[u]]-=2;
}

int _dfs(int i)
{
   int sum=0;
   tr(g[i],it)
   {
      if(p[i]==it->F)continue;
      ans[it->S]=_dfs(it->F);
      sum+=ans[it->S];
   }
   return sum+mark[i];
}
int main()
{
    boost;
      int n;cin>>n;g.resize(n);
      FOR(i,0,n-2){
         int x,y;cin>>x>>y;--x,--y;
         g[x].pb({y,i});g[y].pb({x,i});
      }
      pre(n);
      TCASE{
         int x,y;cin>>x>>y;--x,--y;
         lca(x,y);
      }
      
      _dfs(0);
      FOR(i,0,n-2)cout<<ans[i]<<" ";
   return 0;
}