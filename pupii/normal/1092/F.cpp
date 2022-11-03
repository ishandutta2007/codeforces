#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int W[200010];
int fir[200010],dis[400010],nxt[400010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
ll sum[200010],ans[200010];
il vd dfs(int x,int fa=-1,int dep=0){
	ans[1]+=1ll*dep*W[x];
	sum[x]=W[x];
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa)continue;
		dfs(dis[i],x,dep+1);
		sum[x]+=sum[dis[i]];
	}
}
ll ANS=0;
il vd DFS(int x,int fa=-1){
	ANS=std::max(ANS,ans[x]);
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa)continue;
		ans[dis[i]]=ans[x]-sum[dis[i]]+(sum[1]-sum[dis[i]]);
		DFS(dis[i],x);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<=n;++i)W[i]=gi();
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	dfs(1);DFS(1);
	printf("%lld\n",ANS);
	return 0;
}