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

int a[64];
int main()
{
  boost;
  string s;cin>>s;
  int n = s.length();
  int ans=1;
  FOR(i,0,63){
  	FOR(j,0,63)
  	FOR(k,0,63)
  	a[i]+=((j&k)==i);
  }
  FOR(i,0,n-1){
  	int x=0;
  	if(s[i]>='0' and s[i]<='9')x=s[i]-'0';
  	else if(s[i]>='A' and s[i]<='Z')x=s[i]-'A'+10;
  	else if(s[i]>='a' and s[i]<='z')x=s[i]-'a'+36;
  	else if(s[i]=='-')x=62;
  	else x=63;
  	ans=mul(ans,a[x]);
  }
  
  cout<<ans;
  return 0;
}