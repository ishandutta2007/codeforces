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
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
vvi g;
vector<pair<int,pair<pair<ll,ll>,int>>> h;
vi CX;vll S,SS;
int p[1000001];
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
 
  g.resize(n);
 
  CX.resize(n);S.resize(n);
  SS.resize(n);
  FOR(i,0,m-1){
    int x,y;
    scanf("%d %d",&x,&y);
 
    --x,--y;
    g[x].pb(y);
    g[y].pb(x);
  }
  FOR(i,0,n-1){
    
    if(g[i].empty()){h.pb({0,{{0,0},0}});continue;}
    SS[i]=(g[i][0]+1LL)*(g[i][0]+1LL);
    CX[i]=g[i][0]+1;
    S[i]=g[i][0]+1;
    
    FOR(j,1,sz(g[i])-1)
      CX[i]=CX[i]^(g[i][j]+1),S[i]+=g[i][j]+1,SS[i]+=(g[i][j]+1LL)*(g[i][j]+1LL);
      
    h.pb({g[i].size(),{{S[i],SS[i]},CX[i]}});
  }

  sort(all(h));
  ll ans=0;int ctr=1;
  FOR(i,1,n-1){
    if(h[i]==h[i-1]){++ctr;continue;}
    ans+=(ctr*(ctr-1LL))>>1;
    ctr=1;
  }
  ans+=(ctr*(ctr-1LL))>>1;
  int ans2=0;
  
  FOR(i,0,n-1)
  {
    FOR(j,0,sz(g[i])-1)
      if(S[i]-g[i][j]==S[g[i][j]]-i)
      if(SS[i]-(g[i][j]+1LL)*(g[i][j]+1LL)==SS[g[i][j]]-(i+1LL)*(i+1LL))
      if((CX[i]^(g[i][j]+1)) == (CX[g[i][j]]^(i+1)))
      ans2+=(sz(g[i])==sz(g[g[i][j]]));// and HH[i][j]==HH[g[i][j]][lower_bound(all(g[g[i][j]]),i)-g[g[i][j]].begin()]);
  }
  ans2>>=1;
  printf("%I64d",ans+ans2);
  return 0;
}