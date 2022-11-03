#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,g,im,in;
std::vector<int>va[200010],vb[200010];
int numA[1600010],numB[1600010],cnt;
int fir[1600010],dis[5000010],nxt[5000010],id;ll w[5000010];
void link(int a,int b,ll c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
ll dist[1600010];
std::map<int,int>MA,MB,PA,PB;
void exgcd(int a,int b,int&x,int&y){
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
struct data{
	int p,P;
	data(){}
	data(int x,bool o){p=x;P=!o?(1ll*im*p%n):(1ll*in*p%m);}
}pa[1600010],pb[1600010];
bool operator<(data a,data b){return a.P<b.P;}
bool operator==(data a,data b){return a.p==b.p&&a.P==b.P;}
void chkmn(std::map<int,int>&M,int x,int y){if(!M.count(x)||M[x]>y)M[x]=y;}
std::priority_queue<std::pair<ll,int>>que;
bool vis[1600010],yes[1600010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),g=std::__gcd(n,m);if(g>200000)return puts("-1"),0;
	n/=g,m/=g;
	exgcd(m,n,im,in);
	im=(im%n+n)%n;in=(in%m+m)%m;
	int a=gi(),_;for(int i=1;i<=a;++i)_=gi(),va[_%g].push_back(_/g);
	int b=gi()  ;for(int i=1;i<=b;++i)_=gi(),vb[_%g].push_back(_/g);
	ll ans=0;
	for(int o=0;o<g;++o){
		if(va[o].empty()&&vb[o].empty())return puts("-1"),0;
		MA.clear(),MB.clear();
		for(int x:va[o])chkmn(MA,x,x),chkmn(MB,x%m,x);
		for(int x:vb[o])chkmn(MA,x%n,x),chkmn(MB,x,x);
		cnt=0;a=b=0;
		for(auto[i,w]:MA)pa[++a]={i,0},pa[++a]={(i+n-m%n)%n,0},pb[++b]={i%m,1},pb[++b]={(i+m-n%m)%m,1};
		for(auto[i,w]:MB)pb[++b]={i,1},pb[++b]={(i+m-n%m)%m,1},pa[++a]={i%n,0},pa[++a]={(i+n-m%n)%n,0};
		std::sort(pa+1,pa+a+1);std::sort(pb+1,pb+b+1);
		a=std::unique(pa+1,pa+a+1)-pa-1;
		b=std::unique(pb+1,pb+b+1)-pb-1;
		memset(dist+1,63,8*(a+b));
		PA.clear(),PB.clear();
		for(int x:va[o])PA[x]=1;
		for(int x:vb[o])PB[x]=1;
		for(int i=1;i<=a;++i){
			numA[i]=++cnt;
			if(PA.count(pa[i].p))yes[cnt]=1;else yes[cnt]=0;
			if(MA.count(pa[i].p))dist[cnt]=MA[pa[i].p]*g+o;
		}
		for(int i=1;i<=b;++i){
			numB[i]=++cnt;
			if(PB.count(pb[i].p))yes[cnt]=1;else yes[cnt]=0;
			if(MB.count(pb[i].p))dist[cnt]=MB[pb[i].p]*g+o;
		}
		memset(fir+1,0,cnt*4);id=0;
		for(int i=1;i<a;++i)link(numA[i],numA[i+1],1ll*m*g*(pa[i+1].P-pa[i].P));
		link(numA[a],numA[1],1ll*m*g*(pa[1].P+n-pa[a].P));
		for(int i=1;i<b;++i)link(numB[i],numB[i+1],1ll*n*g*(pb[i+1].P-pb[i].P));
		link(numB[b],numB[1],1ll*n*g*(pb[1].P+m-pb[b].P));
		memset(vis+1,0,cnt);
		for(int i=1;i<=cnt;++i)que.push({-dist[i],i});
		while(!que.empty()){
			int x=que.top().second;vis[x]=1;
			for(int i=fir[x];i;i=nxt[i])
				if(dist[dis[i]]>dist[x]+w[i]){
					dist[dis[i]]=dist[x]+w[i];
					que.push({-dist[dis[i]],dis[i]});
				}
			while(!que.empty()&&vis[que.top().second])que.pop();
		}
		for(int i=1;i<=cnt;++i)if(!yes[i])ans=std::max(ans,dist[i]);
	}
	printf("%lld\n",ans);
	return 0;
}