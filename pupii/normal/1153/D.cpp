#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int f[300010],k;
int s[300010];
int fir[300010],dis[600010],nxt[600010],id,isnleaf[300010];
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int dp[300010];
il vd dfs(int x){
	if(!isnleaf[x]){dp[x]=1;return;}
	else dp[x]=0;
	if(f[x]==1){
		int mn=1e9;
		for(int i=fir[x];i;i=nxt[i]){
			dfs(dis[i]);
			mn=std::min(mn,dp[dis[i]]);
		}
		dp[x]=mn;
	}else{
		for(int i=fir[x];i;i=nxt[i]){
			dfs(dis[i]);
			dp[x]+=dp[dis[i]];
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)f[i]=gi();
	for(int i=2;i<=n;++i)s[i]=gi(),isnleaf[s[i]]=1,link(s[i],i);
	for(int i=1;i<=n;++i)k+=!isnleaf[i];
	dfs(1);
	printf("%d\n",k-dp[1]+1);
	return 0;
}