#include<bits/stdc++.h>//
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m,inv10,pow10[100010],powinv10[100010];
ll ans;
il vd exgcd(int a,int b,int&x,int&y){
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
il int getinv10(int yyb){
	int a=10,b=yyb,x,y;
	exgcd(a,b,x,y);
	return (x%m+m)%m;
}
int fir[100010],dis[200010],nxt[200010],w[200010],id;
int f[100010],siz[100010],rt,N;
bool vis[100010];
il vd link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=c;
}
il vd getrt(int x,int fa){
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
il bool cmp(const std::pair<int,int>&a,const std::pair<int,int>&b){return siz[a.first]<siz[b.first];}
std::map<int,int>orz;
il vd dfs1(int x,int num,int dep,int fa=-1){
	if(orz.find(num)!=orz.end())ans+=orz[num];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i]||vis[dis[i]])continue;
		dfs1(dis[i],(num+1ll*powinv10[dep]*w[i])%m,dep+1,x);
	}
}
il vd dfs2(int x,int num,int dep,int fa=-1){
	++orz[(m-num)%m];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i]||vis[dis[i]])continue;
		dfs2(dis[i],(num+1ll*pow10[dep]*w[i])%m,dep+1,x);
	}
}
il vd solve(int x){
	vis[x]=1;
	std::vector<std::pair<int,int> >A;
	for(int i=fir[x];i;i=nxt[i])if(!vis[dis[i]])A.push_back(std::make_pair(dis[i],w[i]));
	std::sort(A.begin(),A.end(),cmp);
	orz.clear();orz[0]=1;
	for(int i=0;i<A.size();++i){
		dfs1(A[i].first,1ll*inv10*A[i].second%m,2,x);
		dfs2(A[i].first,A[i].second%m,1,x);
	}
	orz.clear();
	for(int i=A.size()-1;~i;--i){
		dfs1(A[i].first,1ll*inv10*A[i].second%m,2,x);
		dfs2(A[i].first,A[i].second%m,1,x);
	}ans+=orz[0];
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]])continue;
		N=siz[dis[i]],rt=0,getrt(dis[i],-1);
		solve(rt);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();inv10=getinv10(m);
	pow10[0]=1;for(int i=1;i<=n;++i)pow10[i]=pow10[i-1]*10ll%m;
	powinv10[0]=1;for(int i=1;i<=n;++i)powinv10[i]=1ll*powinv10[i-1]*inv10%m;
	int a,b,c;
	for(int i=1;i<n;++i)a=gi()+1,b=gi()+1,c=gi(),link(a,b,c);
	rt=0,f[0]=1e9;N=n;getrt(1,-1);
	solve(rt);
	printf("%lld\n",ans);
	return 0;
}