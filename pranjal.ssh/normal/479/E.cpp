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

ll dp[5005][5005];

int main()
{
    boost;
   	int n,a,b,k;cin>>n>>a>>b>>k;
   	FOR(i,a,n)dp[0][i]=1;
   	FOR(K,1,k){
   		FOR(N,1,n){
   			dp[K][N]=dp[K][N-1];
   			if(N<b)
   				dp[K][N]+=dp[K-1][(N+b-1)>>1]-dp[K-1][N]+dp[K-1][N-1];
   			if(N>b)
   				dp[K][N]+=dp[K-1][n]-dp[K-1][((N+b+2)>>1)-1]-dp[K-1][N]+dp[K-1][N-1];
   			dp[K][N]%=INF;
   			if(dp[K][N]<0)dp[K][N]+=INF;
   		}
   	}
   	cout<<dp[k][n];
	return 0;
}