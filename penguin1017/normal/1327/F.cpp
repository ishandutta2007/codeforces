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
const int N=5e5+9;
const ll mod=998244353;
int l[N],r[N],vis[N],x[N];
ll ans=1,dp[N],sum[N];
pii g[N];
bool cmp(pii a,pii b){
	if(a.fi!=b.fi)return a.fi<b.fi;
	return a.se>b.se;
}
int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	rep(i,0,m)scanf("%d%d%d",&l[i],&r[i],&x[i]);
	rep(i,0,k){
		memset(vis,0,sizeof vis);
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		int cnt=0,c=0;
		rep(j,0,m){
			if(x[j]&(1<<i)){
				vis[l[j]]++;
				vis[r[j]+1]--;
			}
			else{
				g[++c]={l[j],r[j]};
			}
		}
		sort(g+1,g+c+1,cmp);
		rep(i,1,c+1){
			while(cnt&&g[cnt].se>=g[i].se)--cnt;
			g[++cnt]=g[i];
		}
		rep(i,1,n+1)vis[i]+=vis[i-1];
		dp[0]=1,sum[0]=1;
		g[cnt+1]={n+1,n+1},c=0;
		int pos=1,lc=0,rc=1;
		for(;pos<=n;++pos){
			if(vis[pos]){	
				while(pos>=g[rc].se)++rc;
				continue;	
			}
			while(pos>=g[lc+1].fi)++lc,sum[lc]=sum[lc-1];
			if(rc>1)dp[lc]=(dp[lc]+sum[lc]-sum[rc-2])%mod;
			else dp[lc]=(dp[lc]+sum[lc])%mod;
			if(lc)sum[lc]=(sum[lc-1]+dp[lc])%mod;
			else sum[lc]=dp[lc];
		//	cout<<pos<<' '<<lc<<' '<<dp[lc]<<"dp\n";
			while(pos>=g[rc].se)++rc;
		}
	//	cout<<cnt<<' '<<dp[cnt]<<"check\n";
		ans=ans*dp[cnt]%mod;
	}
	cout<<(ans+mod)%mod;
}