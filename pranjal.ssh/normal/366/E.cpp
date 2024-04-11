#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 5000


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
#define pra(a,n) cerr<<#a<<" : ";FOR(i,0,n-1)cerr<<a[i]<<" ";cerr<<endl;
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
#define pra(a,n) 
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

const int N = 2e3+69;
int a[N][N];
int T[N*100];
int yo[10][10];
int tr[10][N][N];
#define tl tr
#define bl tr
#define br tr
int main()
{
  boost;
  int n,m,k,s;
  cin>>n>>m>>k>>s;
  FOR(i,1,n)FOR(j,1,m)cin>>a[i][j];
  FOR(i,1,s)cin>>T[i];
  
  FOR(_,1,k)FOR(i,0,n+1)FOR(j,0,m+1)tr[_][i][j]=-INF;
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    tr[x][i][j]=-i+j;
  }

  FOR(x,1,k)FOR(i,1,n)NFOR(j,m,1){
    tr[x][i][j]=max({tr[x][i][j],tr[x][i-1][j],tr[x][i][j+1]});
  }
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    FOR(l,1,k){
      yo[x][l]=max(yo[x][l],tr[l][i][j]+i-j);
    }
  }




  FOR(_,1,k)FOR(i,0,n+1)FOR(j,0,m+1)br[_][i][j]=-INF;
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    br[x][i][j]=i+j;
  }

  FOR(x,1,k)NFOR(i,n,1)NFOR(j,m,1){
    br[x][i][j]=max({br[x][i][j],br[x][i+1][j],br[x][i][j+1]});
  }
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    FOR(l,1,k){
      yo[x][l]=max(yo[x][l],br[l][i][j]-i-j);
    }
  }







  FOR(_,1,k)FOR(i,0,n+1)FOR(j,0,m+1)tl[_][i][j]=-INF;
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    tl[x][i][j]=-i-j;
  }


  FOR(x,1,k)FOR(i,1,n)FOR(j,1,m){
    tl[x][i][j]=max({tl[x][i][j],tl[x][i-1][j],tl[x][i][j-1]});
  }

  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    FOR(l,1,k){
      yo[x][l]=max(yo[x][l],tl[l][i][j]+i+j);
    }
  }







  FOR(_,1,k)FOR(i,0,n+1)FOR(j,0,m+1)bl[_][i][j]=-INF;
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    bl[x][i][j]=i-j;
  }

  FOR(x,1,k)NFOR(i,n,1)FOR(j,1,m){
    bl[x][i][j]=max({bl[x][i][j],bl[x][i+1][j],bl[x][i][j-1]});
  }
  
  FOR(i,1,n)FOR(j,1,m){
    int x = a[i][j];
    FOR(l,1,k){  
      yo[x][l]=max(yo[x][l],bl[l][i][j]-i+j);
    }
  }
  

  int ans = 0;
  FOR(i,2,s)ans=max(ans,yo[T[i-1]][T[i]]);
  cout<<ans;
  return 0;
}