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
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

vi a;int n;
int dp[101][2501];
int f(int i,int s){
   if(s<0)return 0;
   if(i==100)return s==0;
   int &ans = dp[i][s];
   if(ans+1)return ans;
   ans=0;
   FOR(x,0,25){
      ans=add(ans,f(i+1,s-x));
   }
   return ans;
}
int main()
{
   boost;
   memset(dp,~0,sizeof dp);
   TCASE{
     string s; cin>>s;n=s.length();a.resize(n);
     int ss=0;
     FOR(i,0,n-1)a[i]=s[i]-'a',ss+=a[i];
     cout<<(f(100-n,ss)-1+INF)%INF<<"\n";
   }
   return 0;
}