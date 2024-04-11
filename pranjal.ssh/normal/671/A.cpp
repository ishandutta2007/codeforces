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
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
const long double z = 0;

long double dist(ii a, ii b){
	return sqrt((a.F-b.F)*(a.F-b.F+z) + (a.S-b.S)*(a.S-b.S+z));
}
vector<ii> p;
ii a,b,t;

long double dp[100001][2][2];


long double f(int n,int _,int __){
	if(n==p.size()){
		if(_|__)return 0;
		return 1e18;
	}
	long double&ans = dp[n][_][__];
	if(ans!=-1)return ans;
	ans=1e18;
	
	if(!_)ans=min(ans,f(n+1,1,__)+dist(a,p[n])+dist(p[n],t));
	ans=min(ans,f(n+1,_,__)+2*dist(t,p[n]));
	
	if(!__)ans=min(ans,f(n+1,_,1)+dist(b,p[n])+dist(p[n],t));
	ans=min(ans,f(n+1,_,__)+2*dist(t,p[n]));
	return ans;
}
int main()
{
    boost;
    
    
    cin>>a.F>>a.S>>b.F>>b.S>>t.F>>t.S;
    int n;cin>>n;p.resize(n);
    FOR(i,0,n-1)cin>>p[i].F>>p[i].S;
    FOR(i,0,n-1)
    FOR(j,0,1)FOR(k,0,1)dp[i][j][k]=-1;
    cout<<setprecision(15)<<f(0,0,0)<<"\n";
    
	return 0;
}