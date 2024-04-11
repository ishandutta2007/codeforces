#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
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
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int ans,mul;
int nowd;
int A[200010],pA[200010];
int pr[200010],yes[200010],phi[200010],Pr,mu[200010];
int fir[200010],dis[400010],nxt[400010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int dfn[200010],fa[200010],dep[200010],top[200010],son[200010],siz[200010];
void dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		fa[dis[i]]=x;
		dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
void dfs(int x,int tp){
	dfn[x]=++dfn[0];top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])x=y;return x;
}
bool cmp(int a,int b){return dfn[a]<dfn[b];}
int D[400010],m,stk[200010],tp,W[200010];
std::vector<std::pair<int,int>>G[200010];
bool isAnc(int a,int b){return dfn[a]<=dfn[b]&&dfn[b]<dfn[a]+siz[a];}
int sumW[200010],sum2[200010],Mul[200010];
void DFS(int x){
	sumW[x]=W[x];sum2[x]=0;
	for(auto[t,l]:G[x]){
		DFS(t),sumW[x]=(sumW[x]+sumW[t])%mod;
		sum2[x]=(0ll+sum2[x]+sum2[t]+1ll*l*sumW[t])%mod;
	}
}
void DFS(int x,int _sumW,int _sum2){
	//printf("nowd=%d x=%d sW=%d s2=%d %d\n",nowd,x,_sumW,_sum2,1ll*mul*(_sum2+sum2[x])%mod);
	ans=(ans+1ll*mul*(_sum2+sum2[x])%mod*W[x])%mod;
	for(auto[t,l]:G[x])DFS(t,(0ll+_sumW+sumW[x]-sumW[t]+mod)%mod,((0ll+_sum2+sum2[x]-sum2[t]+1ll*l*(0ll+_sumW-sumW[t]*2+sumW[x]+mod*2)%mod)%mod+mod)%mod);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<=n;++i)pA[A[i]=gi()]=i;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	phi[1]=1;mu[1]=1;
	for(int i=2;i<=n;++i){
		if(!yes[i])pr[++Pr]=i,phi[i]=i-1,mu[i]=mod-1;
		for(int j=1;j<=Pr&&i*pr[j]<=n;++j){
			yes[i*pr[j]]=1;
			if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];mu[i*pr[j]]=0;break;}
			phi[i*pr[j]]=phi[i]*(pr[j]-1);mu[i*pr[j]]=mod-mu[i];
		}
	}
	dfs(1);dfs(1,1);
	for(int d=1;d<=n;++d){
		int _=1ll*d*pow(phi[d],mod-2)%mod;
		for(int i=d;i<=n;i+=d)Mul[i]=(Mul[i]+1ll*_*mu[i/d])%mod;
	}
	for(int d=1;d<=n;++d){nowd=d;
		mul=Mul[d];
		m=0;for(int i=d;i<=n;i+=d)D[++m]=pA[i];
		std::sort(D+1,D+m+1,cmp);
		for(int i=1;i<m;++i)D[i+m]=LCA(D[i],D[i+1]);
		m+=m-1;std::sort(D+1,D+m+1,cmp);m=std::unique(D+1,D+m+1)-D-1;
		for(int i=1;i<=m;++i)G[i].clear();
		tp=0;for(int i=1;i<=m;++i){
			while(tp&&!isAnc(D[stk[tp]],D[i]))--tp;
			if(tp)G[stk[tp]].push_back({i,dep[D[i]]-dep[D[stk[tp]]]});stk[++tp]=i;
		}
		for(int i=1;i<=m;++i)if(A[D[i]]%d==0)W[i]=phi[A[D[i]]];else W[i]=0;
		DFS(1);DFS(1,0,0);
	}
	printf("%d\n",1ll*ans*pow(1ll*n*(n-1)%mod,mod-2)%mod);
	return 0;
}