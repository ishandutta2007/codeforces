#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int W[200010],fir[200010],dis[400010],nxt[400010],w[400010],id;
void link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int f[200010],siz[200010],rt,N;
bool vis[200010];
void getrt(int x,int fa=-1){
	siz[x]=1;f[x]=0;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i]||vis[dis[i]])continue;
		getrt(dis[i],x);
		siz[x]+=siz[dis[i]];
		f[x]=std::max(f[x],siz[dis[i]]);
	}
	f[x]=std::max(f[x],N-siz[x]);
	if(f[x]<f[rt])rt=x;
}
double ans=1e233,SUM,DAO;
int A;
void DFS(int x,ll sum=0,int fa=-1){
	SUM+=sum*sqrt(sum)*W[x];
	DAO+=1.5*sqrt(sum)*W[x];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		DFS(dis[i],sum+w[i],x);
	}
}
void solve(int x){
	vis[x]=1;
	SUM=0;
	double _DAO=-1e233;int son=-1;
	for(int i=fir[x];i;i=nxt[i]){
		DAO=0;
		DFS(dis[i],w[i],x);
		if(DAO>_DAO)_DAO=DAO,son=dis[i];
	}
	if(SUM<ans)ans=SUM,A=x;
	if(~son&&!vis[son])rt=0,N=siz[son],getrt(son),solve(rt);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b,c;
	for(int i=1;i<=n;++i)W[i]=gi();
	for(int i=1;i<n;++i)a=gi(),b=gi(),c=gi(),link(a,b,c),link(b,a,c);
	f[0]=1e9;N=n;getrt(1);solve(rt);
	printf("%d %.14lf\n",A,ans);
	return 0;
}