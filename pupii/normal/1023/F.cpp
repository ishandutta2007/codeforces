#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[500010],dis[1000010],nxt[1000010],w[1000010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int fa[500010],FA[500010],bel[500010],dep[500010],faw[500010];
int HD(int x){return FA[x]==x?x:FA[x]=HD(FA[x]);}
void dfs(int x){for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i])faw[dis[i]]=w[i],bel[dis[i]]=bel[x],fa[dis[i]]=x,dep[dis[i]]=dep[x]+1,dfs(dis[i]);}
int eA[500010],eB[500010],eW[500010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),m=gi(),a,b;
	for(int i=1;i<=n;++i)FA[i]=i;
	for(int i=1;i<=k;++i)a=gi(),b=gi(),link(a,b,1),link(b,a,1),FA[HD(a)]=HD(b);
	ll ans=0;
	for(int i=1;i<=m;++i){
		eA[i]=gi(),eB[i]=gi(),eW[i]=gi();
		if(HD(eA[i])!=HD(eB[i]))link(eA[i],eB[i],0),link(eB[i],eA[i],0),FA[HD(eA[i])]=HD(eB[i]);
	}
	for(int i=1;i<=n;++i)if(!fa[i])bel[i]=i,dep[i]=1,dfs(i);
	for(int i=1;i<=n;++i)FA[i]=i;
	for(int i=1;i<=n;++i)if(fa[i]&&!faw[i])FA[i]=fa[i];
	for(int i=1,w;i<=m;++i){
		a=eA[i],b=eB[i];w=eW[i];
		while(1){
			a=HD(a),b=HD(b);
			if(a==b)break;
			ans+=w,--k;
			if(dep[a]>dep[b])FA[a]=fa[a];
			else FA[b]=fa[b];
		}
	}
	printf("%lld\n",k?-1:ans);
	return 0;
}