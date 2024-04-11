#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include<bits/stdc++.h>
typedef unsigned long long ll;
#define pr std::pair<int,int>
#define fi first
#define se second
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char map[20][20];
ll dp[1<<18|1][18],block[1<<18|1];
ll ans[1<<18|1];
ll fuck[19][1<<18|1],Fuck[19];
int n;
void FWT(ll*A,int t){
	for(int i=0;i<n;++i)
		for(int j=0;j<1<<n;++j)
			if(~j&1<<i)A[j|(1<<i)]+=t*A[j];
}
std::map<std::multiset<int>,ll>M;
std::multiset<int>cur;
int cnt;
int fir[1010],dis[10010],nxt[10010],w[10010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int build(int sum,int lst){
	int x=++cnt;
	if(sum==n)return M[cur]=x;
	for(int i=lst;i<=n-sum;++i){
		if(i<n-sum&&sum+i+i>n)continue;
		cur.insert(i);
		link(x,build(sum+i,i),i);
		cur.erase(cur.find(i));
	}
	return x;
}
ll sum[1010];
void dfs(int x,int p,ll num){
	if(!fir[x]){sum[x]+=num;return;}
	for(int i=fir[x];i;i=nxt[i])dfs(dis[i],p,num*Fuck[w[i]]);
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=0;i<n;++i)scanf("%s",map[i]);
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;++i)dp[1<<i][i]=1;
	for(int i=1;i<1<<n;++i){
		for(int k=0;k<n;++k)
			if(dp[i][k]){
				block[i]+=dp[i][k];
				for(int o=0;o<n;++o)
					if((~i>>o&1)&&map[o][k]=='1')
						dp[i|(1<<o)][o]+=dp[i][k];
			}
	}
	for(int i=0;i<1<<n;++i)fuck[__builtin_popcount(i)][i]+=block[i];
	for(int i=0;i<=n;++i)FWT(fuck[i],1);
	build(0,1);
	for(int i=0;i<1<<n;++i){
		for(int j=0;j<=n;++j)Fuck[j]=fuck[j][i];
		dfs(1,i,n+1+__builtin_parity(i)&1?1:-1);
	}
	for(int i=0;i<1<<n-1;++i){
		cur.clear();
		for(int l=0,r;l<n;l=r+1){
			r=l;while(i>>r&1)++r;
			cur.insert(r-l+1);
		}
		ans[i]=sum[M[cur]];
	}
	for(int i=0;i<n-1;++i)
		for(int j=0;j<1<<n-1;++j)
			if(j&1<<i)ans[j^(1<<i)]-=ans[j];
	for(int i=0;i<1<<n-1;++i)printf("%llu ",ans[i]);
	return 0;
}