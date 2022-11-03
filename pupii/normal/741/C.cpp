#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[100010],b[100010],fir[200010],dis[400010],nxt[400010],id;
void link(int a,int b){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a;
}
bool vis[200010],col[200010];
void dfs(int x){
	vis[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]])continue;
		col[dis[i]]=col[x]^1;
		dfs(dis[i]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)link(i*2,i*2-1);
	for(int i=1;i<=n;++i)a[i]=gi(),b[i]=gi(),link(a[i],b[i]);
	for(int i=1;i<=2*n;++i)if(!vis[i])dfs(i);
	for(int i=1;i<=n;++i)printf("%d %d\n",col[a[i]]+1,col[b[i]]+1);
	return 0;
}