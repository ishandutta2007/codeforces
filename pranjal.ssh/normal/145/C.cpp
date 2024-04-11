#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007


#define debug
#ifndef debug
  #define endl "\n"
#endif
#ifdef debug
  #define pr(x)                  cerr << #x << ": " << x << endl;
  #define pr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
  #define pr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
  #define pr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
  #define pr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
  #define pr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
  #define prc(a) for(auto it: a) cerr<<(it)<<" "; cerr<<endl
  #define pra(a,n) for(int i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<endl
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;

#else
  #define pr(x)
  #define pr2(x, y)
  #define pr3(x, y, z)
  #define pr4(a, b, c, d)
  #define pr5(a, b, c, d, e)
  #define pr6(a, b, c, d, e, f)
  #define tr(c,it)
  #define prc(a)
  #define pra(a,n)
  #define prdd(a, r, c)
#endif

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

const int N = 1e5;
int u;
map<int,int> l;
int fac[N+1];
int inv[N+1];
int ifac[N+1];
inline int C(int n,int k)
{
  if(k>n)return 0;
  return mul(fac[n],mul(ifac[k],ifac[n-k]));
}
int dp[1200][1200];
int main()
{
  boost;
  fac[0]=1;ifac[0]=1;inv[1]=1;
  FOR(i,1,N)fac[i]=mul(fac[i-1],i);
  FOR(i,2,N)inv[i]=(-(INF/i)*1LL*inv[INF%i])%INF+INF;
  FOR(i,1,N)ifac[i]=mul(ifac[i-1],inv[i]);

  int n,k;cin>>n>>k;
  FOR(i,0,n-1){
    int x;cin>>x;
    int y=x;bool ok=1;
    while(y>0)
      ok&=(y%10==4 or y%10==7),y/=10;
    if(ok)
      l[x]++;
    else u++;
  }
  
  dp[0][0]=1;
  int i=1;
  for(auto it:l)
  {
    dp[i][0]=1;
    FOR(j,1,min(k,sz(l)))
    dp[i][j]=add(dp[i-1][j],mul(dp[i-1][j-1],it.S));
    ++i;
  }
  int ans=0;
  FOR(j,0,min(k,sz(l)))
  {
    ans=add(ans,mul(dp[i-1][j],C(u,k-j)));
  }
  cout<<ans;
  return 0;
}