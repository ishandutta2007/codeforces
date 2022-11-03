#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define inv2 500000004
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int p2[500010];
int fir[500010],dis[1000010],nxt[1000010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int FA[500010];
int hd(int x){return FA[x]==x?x:FA[x]=hd(FA[x]);}
bool Union(int x,int y){
	x=hd(x),y=hd(y);
	return x==y?0:(FA[x]=y,1);
}
int d[500010],fa[500010],dep[500010],dist[500010],cx[500010],cy[500010],cL[500010],c,sd[500010];
void dfs(int x){
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		fa[dis[i]]=x;dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
	}
}
std::vector<int>cir[500010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=n;++i)FA[i]=i;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),++d[a],++d[b],Union(a,b)?link(a,b),link(b,a),0:(cx[++c]=a,cy[c]=b);
	dep[1]=1,dfs(1);
	p2[0]=1;for(int i=1;i<=500000;++i)p2[i]=1ll*inv2*p2[i-1]%mod;
	for(int i=1;i<=c;++i){
		a=cx[i],b=cy[i];cL[i]=1;
		while(dep[a]>dep[b])cir[a].push_back(i),sd[i]+=d[a],a=fa[a],++cL[i];
		while(dep[a]<dep[b])cir[b].push_back(i),sd[i]+=d[b],b=fa[b],++cL[i];
		while(a^b)cir[a].push_back(i),cir[b].push_back(i),sd[i]+=d[a]+d[b],a=fa[a],b=fa[b],cL[i]+=2;
		cir[a].push_back(i);sd[i]+=d[a];sd[i]-=cL[i];
	}
	int V2=0,E2=0,C2=0,VE=0,VC=0,EC=0;//get E(x^2)
	V2=(1ll*n*p2[1]+1ll*n*(n-1)%mod*p2[2])%mod;//V^2

	ll s=1ll*m*m;//E^2
	E2=(E2+1ll*p2[2]*m)%mod;s-=m;// #1
	for(int i=1;i<=n;++i)E2=(E2+1ll*d[i]*(d[i]-1)%mod*p2[3])%mod,s-=1ll*d[i]*(d[i]-1);//#2
	E2=(E2+s%mod*p2[4])%mod;//#3

	//C^2
	for(int i=1,s=0;i<=c;++i)C2=(C2+1ll*p2[cL[i]]*(2*s+1))%mod,s=(s+p2[cL[i]])%mod;//#1
	for(int i=1;i<=n;++i){
		int s=0,S=0;
		for(int j:cir[i])S=(S+2ll*p2[cL[j]]*s)%mod,s=(s+p2[cL[j]])%mod;//#2
		C2=(C2+S)%mod;
	}
	VE=(1ll*m*(p2[2]*2+1ll*(n-2)*p2[3]%mod))%mod;//VE

	for(int i=1;i<=c;++i)VC=(VC+1ll*p2[cL[i]]*cL[i]+1ll*p2[cL[i]+1]*(n-cL[i]))%mod;//VC

	for(int i=1;i<=c;++i)EC=(EC+1ll*p2[cL[i]]*cL[i]+1ll*p2[cL[i]+1]*(sd[i]-cL[i])+1ll*p2[cL[i]+2]*(m-sd[i]))%mod;//EC

	int Ex2=(0ll+V2+E2+C2-2*VE%mod+mod+2*VC-2*EC%mod+mod)%mod;

	int V=1ll*n*p2[1]%mod,E=1ll*m*p2[2]%mod,C=0;

	for(int i=1;i<=c;++i)C=(C+p2[cL[i]])%mod;

	int Ex=(0ll+V+C-E+mod)%mod;

	printf("%d\n",(Ex2-1ll*Ex*Ex%mod+mod)%mod);
	return 0;
}