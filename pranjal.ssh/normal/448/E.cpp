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
typedef vector<ii > vii;
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
vll d;
vi yo[10000];
vii f(int k){
	
	if(k==1)
	{
		vii ans;
		FOR(i,0,sz(d)-1)ans.pb(ii(i,i));
		return ans;
	}
	if(!(k&1)){
		vii ans;
		vii bc = f(k-1);
		for(auto it:bc)
		{	
			for(auto itt:yo[it.F])
			{ans.pb(ii(itt,it.S));if(ans.size()==N)break;}
			if(ans.size()==N)break;
		}
		return ans;
	}
	vii bc = f((k+1)>>1);
	vi mp[sz(d)+1];
	for(auto it:bc)
	mp[it.S].pb(it.F);
	vii ans;
	for(auto it:bc){
		for(auto itt:mp[it.F])
			{ans.pb(ii(itt,it.S));if(ans.size()==N)break;}
		if(ans.size()==N)break;
	}
	return ans;
}
int main()
{
    boost;
    ll n,k;
    cin>>n>>k;
    if(k==0){cout<<n;return 0;}
    k=min(k,N+0LL);
    for(ll i=1;i*i<=n;++i){
    	if(n%i)continue;
    	d.pb(i);
    	if(i*i!=n)d.pb(n/i);
    }
    sort(all(d));
    
    FOR(i,0,sz(d)-1)FOR(j,0,sz(d)-1)	
    	if(d[i]%d[j]==0)yo[i].pb(j);
    
    
	vii ans = f(k);    
	FOR(i,0,min(N,sz(ans))-1)
	cout<<d[ans[i].F]<<" ";
	return 0;
}