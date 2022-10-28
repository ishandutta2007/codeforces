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
#define prc(a) cerr<<#a<<" : ";for(auto it:a)cerr<<it<<" ";cerr<<endl;
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
#define prc(a)
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
vi g[N+1];
int mark[N],p[N],dep[N];
int want[N];
bool pres[N];
bool dfs(int i){
  bool can=1;
  for(int it:g[i]){
    dep[it]=dep[i]+1;
    can&=(mark[p[it]]<=dep[want[it]]);
    mark[it]=dep[want[it]];
    can&=(mark[want[it]]>=dep[want[it]]);
    can&=dfs(it);
  }
  return can;
}
void print(int i){
  for(int it:g[i])
    print(it);
  if(pres[i])cout<<i+1<<"\n";
}

int main()
{
  boost;
  int n,m;cin>>n>>m;
  memset(p,-1,sizeof(p));
  FOR(i,0,m-1){
    int x,y;cin>>x>>y;
    g[x-1].pb(y-1);
    p[y-1]=x-1;
  }
  FOR(i,0,n-1)cin>>want[i],want[i]--,pres[want[i]]=1;
  FOR(i,0,n-1){
    if(p[i]==-1){
      if(!dfs(i))
        {cout<<-1;return 0;}
    }
  }
  prc(g[0]);
  cout<<count_if(pres,pres+n,[](const int &x){return x;})<<"\n";
  FOR(i,0,n-1){
    if(p[i]==-1)
      print(i);
  }
  return 0;
}