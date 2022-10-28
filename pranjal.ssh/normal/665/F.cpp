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



ll L[316230],H[316230];
int main()
{
    boost;
 
    
	ll n;
	cin>>n;
	ll ans=0;
	
	// cout<<ans<<" ";	
	ll nr = sqrt((long double)n);
	
	
	FOR(i,1,nr)L[i]=n/i-1;
	FOR(i,1,nr)H[i]=i-1;
	
	for(ll i=2;i<=nr;++i)
	{
		if(H[i]==H[i-1])continue;
		FOR(j,1,nr)
		{
			if(i*i>n/j)break;
			L[j]-=(j*i<=nr?L[j*i]:H[n/(j*i)])-H[i-1];
		}
		NFOR(j,nr,2)
		{
			if(i*i>j)break;
			H[j]-=H[j/i]-H[i-1];
		}
	}
	ll x=2;
	while(x*x*x<=n)ans+=(H[x]!=H[x-1]),++x;
	FOR(i,2,nr)
	if(H[i]!=H[i-1])ans+=L[i]-H[i];
	cout<<ans<<"\n";
	return 0;
}