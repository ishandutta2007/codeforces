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
int a[N+1];
int f[N+2];
int cum[N+2];//no pun intended
vi fac[N+1];
int sv[N+1];

int expo(int n,int m)
{
  if(m==0)return 1;
  int x = expo(n,m>>1);
  x=mul(x,x);
  return m&1?mul(x,n):x;
}
int main()
{
  boost;
  FOR(i,1,N)sv[i]=i;
  FOR(i,2,316)if(sv[i]==i)for(int j=i*i;j<=N;j+=i)sv[j]=i;
  fac[1]={1};
  FOR(i,2,N)
  {
    fac[i]=fac[i/sv[i]];
    for(auto it:fac[i/sv[i]])
      fac[i].pb(sv[i]*it);
    sort(all(fac[i]));fac[i].erase(unique(all(fac[i])),fac[i].end());
  }
  int n;cin>>n;FOR(i,1,n)cin>>a[i],f[a[i]]++;
  NFOR(i,N,1)cum[i]=cum[i+1]+f[i];
  int ans=0;
  FOR(i,1,N)
  {
    int _ans=1;
    NFOR(j,sz(fac[i])-2,0)
      _ans=mul(_ans,expo(1+j,cum[fac[i][j]]-cum[fac[i][j+1]]));
    int x = mul(_ans,expo(sz(fac[i]),cum[fac[i].back()])) //no pun intended
          - mul(_ans,expo(sz(fac[i])-1,cum[fac[i].back()]));
    if(x<0)x+=INF;
    ans=add(ans,x);
  }
  cout<<ans;
  
  return 0;
}