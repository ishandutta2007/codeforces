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


#define TRACE

#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T,U>& a){out<<"["<<a.first<<" "<<a.second<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const map<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const multimap<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
} 
#else
#define trace(...)
#define pra(a,n)
#define praa(a,n,m)
#endif


#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

const int N = 1e5;
vi g[N],t[N];
int p[N],sum[N],jump[17][N],tnum[N],tsub[N],l[N],p2[N+1];
int num[N],low[N],ctr,in[N],root[N],size[N],up_here[N],up_there[N];
stack<int> bc;

void dfs(int i,int par){
  num[i] = low[i] = ++ctr;
  bc.push(i);in[i]=1;
  for(int j:g[i]){
    if(num[j]==-1) dfs(j,i);
    if(j != par and in[j]) low[i] = min(low[i], low[j]);
  }
  if(low[i] == num[i]){
    while(bc.top()!=i)
      root[bc.top()]=i,in[bc.top()]=0,
      bc.pop();
    root[bc.top()]=i,in[bc.top()]=0,bc.pop();
  }
}
void dfst(int i,int par){
  sum[i]+=(size[i]>1);
  tnum[i]=++ctr;
  tsub[i]=1;
  p[i]=par;
  for(int j:t[i]){
    if(j==par)continue;
    l[j]=l[i]+1;
    sum[j]+=sum[i];
    dfst(j,i);
    tsub[i]+=tsub[j];
  }
}
int qry(int x,int y){
  int X=x,Y=y;
  x=root[x],y=root[y];
  if(l[x]<l[y])swap(x,y);
  if(x==y) return p2[size[x]>1];
  int u = x;
  NFOR(i,16,0){
    int par = jump[i][u];
    if(par==-1)continue;
    if(tnum[y]<tnum[par] or tnum[y]>=tnum[par]+tsub[par])
      u=par;
  }
  u=p[u];
  
  return p2[sum[x]+sum[y]-2*sum[u]+(size[u]>1)];
}
int main()
{
  boost;
  int n,m;cin>>n>>m;
  
  FOR(i,0,m-1){
    int x,y;cin>>x>>y;--x,--y;
    g[x].pb(y);g[y].pb(x);
  }
  memset(num,-1,sizeof num);
  dfs(0,-1);
  
  FOR(i,0,n-1)size[root[i]]++;
  FOR(i,0,n-1){
    for(int j:g[i]){
      if(i>j)continue;
      if(root[i]!=root[j])
        t[root[i]].pb(root[j]),
        t[root[j]].pb(root[i]);
    }
  }
  
  ctr=0;
  FOR(i,0,n-1)if(root[i]==i){dfst(0,-1);break;}

  FOR(i,0,n-1){
    for(int j:g[i]){
      if(p[root[i]]==root[j])
        up_here[root[i]]=i,
        up_there[root[i]]=j;
    }
  }


  FOR(i,0,16)FOR(j,0,n-1)jump[i][j]=-1;
  FOR(i,0,n-1)jump[0][i]=p[i];
  p2[0]=1;
  FOR(i,1,N)p2[i]=add(p2[i-1],p2[i-1]);

  FOR(i,1,16){
    FOR(j,0,n-1){
      if(jump[i-1][j]!=-1)
      jump[i][j]=jump[i-1][jump[i-1][j]];
    }
  }

  
  TCASE{
    int i,j;
    cin>>i>>j;
    --i,--j;
    cout<<qry(i,j)<<"\n";
  }
  return 0;
}