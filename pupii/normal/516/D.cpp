#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,fir[100010],dis[200010],nxt[200010],w[200010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
void getdia(int x,int&o,ll&d,ll dist=0,int fa=-1){
	if(dist>d)d=dist,o=x;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		getdia(dis[i],o,d,dist+w[i],x);
	}
}
ll d[100010],du[100010],dv[100010];
void dfs(int x,ll*d,int fa=-1){
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		d[dis[i]]=d[x]+w[i];
		dfs(dis[i],d,x);
	}
}
int sd[100010],st[17][100010],dfn[100010],end[100010];
void DFS(int x,int fa=-1){
	dfn[x]=++dfn[0];
	for(int i=fir[x];i;i=nxt[i])if(fa!=dis[i])DFS(dis[i],x);
	end[x]=dfn[0];
}
int t[100010];
void update(int x){while(x<=n)--t[x],x+=x&-x;}
int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();int a,b,c;
	for(int i=1;i<n;++i)a=gi(),b=gi(),c=gi(),link(a,b,c),link(b,a,c);
	int u,v;ll _d=-1;
	getdia(1,u,_d);_d=-1,getdia(u,v,_d);
	dfs(u,du),dfs(v,dv);
	for(int i=1;i<=n;++i)d[i]=std::max(du[i],dv[i]);
	int rt=1;
	for(int i=2;i<=n;++i)if(d[i]<d[rt])rt=i;
	DFS(rt);
	for(int i=1;i<=n;++i)sd[i]=i;
	std::sort(sd+1,sd+n+1,[&](int a,int b){return d[a]>d[b];});
	int Q=gi();
	while(Q--){
		ll L=gi();
		for(int i=1;i<=n;++i)t[i]=1;
		for(int i=1;i<=n;++i)if(i+(i&-i)<=n)t[i+(i&-i)]+=t[i];
		int ans=0;
		for(int _=1,i,j=1;_<=n;++_){
			i=sd[_];
			while(j<=n&&d[sd[j]]-d[i]>L)update(dfn[sd[j]]),++j;
			ans=std::max(ans,query(end[i])-query(dfn[i]-1));
		}
		printf("%d\n",ans);
	}
	return 0;
}