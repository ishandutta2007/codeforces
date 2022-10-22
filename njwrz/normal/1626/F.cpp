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
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[800005];
int ans,a[20];
int mod=998244353,p[20];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,now,x,y,k,M;
	cin>>n>>now>>x>>y>>k>>M;
	int num=1,ans=0;
	rep(i,1,k)num=num*i/__gcd(num,i);
	dp[now%num]++;
	p[0]=1;
	FOR(i,1,k){
		p[i]=p[i-1]*n%mod;
		a[i]=p[i-1]*i%mod;
	}
	ans=a[k]*now%mod;
	FOR(i,2,n){
		now=(now*x+y)%M;
		dp[now%num]++;
		ans=(ans+now*a[k])%mod;
	}
	FOR(i,1,k){
		rep(j,0,num)if(dp[j]){
			int now=j%i;
			int t=dp[j];dp[j]=0;
			add(ans,mod-now*t%mod*a[k-i]%mod);
			add(dp[j-now],t);
			dp[j]=(dp[j]+t*(n-1))%mod;
		}
	}
	cout<<ans;
	RE 0;
}