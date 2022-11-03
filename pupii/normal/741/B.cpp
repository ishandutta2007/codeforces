#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[1010],dis[200010],nxt[200010],id,W[1010],B[1010],vis[1010];
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int a[1010],o,f[1010],_[1010],sW,sB;
void dfs(int x){
	vis[x]=1;a[++o]=x;sW+=W[x],sB+=B[x];
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]])continue;
		dfs(dis[i]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),w=gi(),x,y;
	for(int i=1;i<=n;++i)W[i]=gi();
	for(int i=1;i<=n;++i)B[i]=gi();
	for(int i=1;i<=m;++i)x=gi(),y=gi(),link(x,y),link(y,x);
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		o=sW=sB=0;dfs(i);
		memcpy(_,f,sizeof _);
		for(int j=1;j<=o;++j)
			for(int k=w;k>=W[a[j]];--k)
				f[k]=std::max(f[k],_[k-W[a[j]]]+B[a[j]]);
		for(int k=w;k>=sW;--k)f[k]=std::max(f[k],_[k-sW]+sB);
	}
	printf("%d\n",f[w]);
	return 0;
}