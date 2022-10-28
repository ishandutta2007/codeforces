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


vii a;
int dp[601][601];

char ans[1201];
int f(int i,int n)
{
  if(!n)return 1;
  if(a.size()-i<n)return 0;

  int &ans = dp[i][n];
  if(~ans)return ans;
  ans=0;
  FOR(x,a[i].F,min(2*n,a[i].S))
  {
    if(x&1^1)continue;
    ans|=(f(i+1,x>>1)&f(i+1+(x>>1),n-(x>>1)-1));
    if(ans)break;
  }
  return ans;
}
void print(int i,int n,int pos=1)
{
  if(!n)return;

  FOR(x,a[i].F,min(2*n,a[i].S))
  {
    if(x&1^1)continue;
    if(f(i+1,x>>1)&f(i+1+(x>>1),n-(x>>1)-1))
    {
      ans[pos]='(';
      ans[pos+x]=')';
      print(i+1,x>>1,pos+1);
      print(i+1+(x>>1),n-(x>>1)-1,pos+x+1);
      break;
    }
  }
}
int main()
{
  boost;
  int n;cin>>n;a.rz(n+1);
  FOR(i,1,n)cin>>a[i].F>>a[i].S;
  memset(dp,~0,sizeof dp);
  bool can =f(1,n);
  if(can^1)cout<<"IMPOSSIBLE\n";
  else
  {print(1,n);FOR(i,1,2*n)cout<<ans[i];}
  return 0;
}