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

typedef ll XXX;
struct BIT1 // Point update,query
{
   vector<XXX> t;XXX n;BIT1(){n=0;}
   BIT1(XXX sz){ n=sz; t.clear(); t.rz(sz+1);}
   void clr(XXX sz){ n=sz; t.clear(); t.rz(sz+1);}
   void upd(XXX i, XXX val){ while(i<=n) t[i]+=val, i+=i&-i;}
   XXX qry(XXX i){XXX ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};
const int N = 1e6;
int a[N];
vi yo;
int main()
{
   boost;
   int n;cin>>n;
   FOR(i,0,n-1)cin>>a[i],yo.push_back(a[i]);
   sort(all(yo));yo.erase(unique(all(yo)),yo.end());
   FOR(i,0,n-1)a[i]=lower_bound(all(yo),a[i])-yo.begin()+1;

   BIT1 b1(n+5);BIT1 b2(n+5);
   ll s1=0,s2=0;
   ll t1=0,t2=0;
   FOR(i,0,n-1){
      ll now1 =s1-b1.qry(a[i]);
      b1.upd(a[i],1),++s1;
      t1+=now1;
      ll now2=s2-b2.qry(a[i]);
      b2.upd(a[i],now1),s2+=now1;
      t2+=now2;
   }
   cout<<t2;
   return 0;
}