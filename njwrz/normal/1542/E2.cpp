#include<bits/stdc++.h>
#define int long long
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
using namespace std;
int dp[2][505*255],p[2][505*255],mul[505],mod; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>mod;
	mul[0]=1;
	FOR(i,1,n)mul[i]=mul[i-1]*(n-i+1)%mod;
	int T=1,ans=0;
	dp[0][0]=1;
	rep(i,1,n){
		FILL(dp[T],0);
		int m=(i-1)*(i-2)/2;
		FOR(j,0,m)add(dp[T][j],dp[T^1][j]),add(dp[T][j+i],mod-dp[T^1][j]);
		m+=i-1;p[T][0]=dp[T][0];
		FOR(j,1,m)add(dp[T][j],dp[T][j-1]),p[T][j]=dp[T][j],add(p[T][j],p[T][j-1]);
		int sum=0,now=0,add=0;
		FOR(j,1,m){
			sum=(sum+now*dp[T][j])%mod;
			if(j-1<=i){
				add=0;
				for(int k=j-1;k>=0;k--){
					add+=dp[T][k]*(i-(j-1-k));
				}
				add%=mod;
			}else{
				add+=dp[T][j-1]*i;add-=p[T][j-2]-p[T][j-i-2];
				add%=mod;
			}
			now=(now+add)%mod;
		}
		ans=(ans+mul[n-i-1]*sum)%mod;
		T^=1;
	}
	cout<<(ans+mod)%mod;
	RE 0;
}