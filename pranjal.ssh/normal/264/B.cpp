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

int sv[100001];
int dp[100001];
int main()
{
    boost;
    FOR(i,1,100000)sv[i]=i;
    FOR(i,2,316)
    if(sv[i]==i)
    for(int j=i*i;j<=100000;j+=i)sv[j]=i;
    
    int n;cin>>n;
    
    FOR(i,0,n-1){
    	int x;cin>>x;
    	vi p;int y=x;
    	while(y>1){p.pb(sv[y]);y/=sv[y];}
    	int yo=0;
    	for(int it:p)yo=max(yo,dp[it]);
    	for(int it:p)dp[it]=yo+1;
    }
    
    cout<<max(1,*max_element(dp,dp+100001));
	return 0;
}