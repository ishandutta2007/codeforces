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
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

int main()
{
  boost;
  int n,l;cin>>n>>l;
  vi x(n+1),b(n+1),p(n+1);
  FOR(i,1,n)cin>>x[i]>>b[i];
  vector<double> dp(n+1);
  double st = 0; double en = 1e3;
  FOR(_,0,40){
  	fill(all(p),0);
  	fill(all(dp),1e6);
  	double r = (st+en)/2;
  	p[0]=0;dp[0]=0;
  	FOR(i,1,n){
  		FOR(j,0,i-1)
  		if(dp[i]>dp[j]+std::sqrt(abs(x[i]-x[j]-l))-r*b[i])
  			dp[i]=dp[j]+std::sqrt(abs(x[i]-x[j]-l))-r*b[i],
  			p[i]=j;
  	}
  	if(dp[n]<0)
  		en=r;
    else 
  		st=r;
  }

  vi ans;
  int j = n;
  while(j){
  	ans.pb(j);
  	j=p[j];
  }
  reverse(all(ans));
  for(auto it:ans)cout<<it<<" ";
  return 0;
}