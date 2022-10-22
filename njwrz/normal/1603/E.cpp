#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int C[205][205];
int dp[205][205][205];
int n,mod; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
	if(n==1){
		cout<<2;
		RE 0;
	}
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	int ans=0;
	FOR(mi,2,n+1){
		FOR(i,mi,n+1){
			FOR(j,0,n)FOR(k,0,mi-(n-j)*(i-mi))dp[i][j][k]=0;
		}
		dp[mi][0][0]=1;
		FOR(i,mi,n+1){
			FOR(j,(i==mi)?0:(n-mi/(i-mi)),n){
				FOR(k,0,mi-(n-j)*(i-mi))if(dp[i][j][k]){
					FOR(to,(i==mi),n-j){
						int now=to*(i-mi)+k;
						if(now>mi)break;
						if(mi*(j+to)+now>mi*i)break;
						if(j+to<n)add(dp[i+1][j+to][now],1ll*dp[i][j][k]*C[n-j][to]%mod);
						else add(ans,1ll*dp[i][j][k]*C[n-j][to]%mod);
					}
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}