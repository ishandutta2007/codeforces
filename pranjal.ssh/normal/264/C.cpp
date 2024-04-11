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


int v[100001];
int c[100001];
vll dp(200001);
int OFF=1e5;
int main()
{
    boost;
    int n,m;cin>>n>>m;FOR(i,1,n)cin>>v[i];FOR(i,1,n)cin>>c[i];
    while(m--){
    	ll a,b;cin>>a>>b;
    	fill(all(dp),-1e17);
    	pair<ll,int> a1,a2;
    	a1={0,1e6};a2={-1e17,1e7};
    	FOR(i,1,n){
    		dp[c[i]+OFF]=max(dp[c[i]+OFF],dp[c[i]+OFF]+v[i]*a);
    		dp[c[i]+OFF]=max(dp[c[i]+OFF],v[i]*b);
    		dp[c[i]+OFF]=max(dp[c[i]+OFF],(a1.S==c[i]?a2.F:a1.F)+v[i]*b);
    		pair<ll,int> now ={dp[c[i]+OFF],c[i]};

    		if(now>=a1){
    			if(now.S!=a1.S)a2=a1;
    			a1=now;
    		}
    		else if(now>a2 and now.S!=a1.S)a2=now;
    	}
    	cout<<a1.F<<"\n";
    }
	return 0;
}