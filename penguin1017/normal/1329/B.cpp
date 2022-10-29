#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
ll sum[32];
ll dp[32];
int main(){
	int t;
	scanf("%d",&t);;
	while(t--){
		int m,d,last=0,k;
		scanf("%d%d",&d,&m);
		for(k=1;(1<<k)-1<=d;++k){
			sum[k]=(1<<k)-1-last;
			last=(1<<k)-1;
		}
		sum[k]=d-last;
		if(!sum[k])--k;
		ll ans=0;
		rep(len,1,k+1){
			memset(dp,0,sizeof dp);
			dp[0]=1;
			rep(i,1,k+1){
				for(int mask=max(len,i);mask;--mask){
					dp[mask]=(dp[mask]+dp[mask-1]*sum[i])%m;
				}
			}
			ans=(ans+dp[len])%m;
		}
		printf("%lld\n",ans);
	} 
}