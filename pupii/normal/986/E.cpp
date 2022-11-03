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
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int val[100010];
int fir[100010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int pr[670000],d[10000010],pd[10000010],PD[10000010],max[670000],smax[670000],N=10000000,P,m;
bool yes[10000010];
int fa[100010],son[100010],top[100010],dep[100010],siz[100010];
void dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa[x])continue;
		fa[dis[i]]=x;dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
void dfs(int x,int tp){
	top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa[x]&&dis[i]!=son[x])dfs(dis[i],dis[i]);
}
int rt[100010],ls[20000010],rs[20000010],sum[20000010],mul[20000010],cnt;
#define mid ((l+r)>>1)
void update(int&x,int l,int r,const int&p,const int&v){
	++cnt;ls[cnt]=ls[x],rs[cnt]=rs[x],sum[cnt]=sum[x],mul[cnt]=mul[x];
	x=cnt;++sum[x];mul[x]=1ll*mul[x]*v%mod;if(l==r)return;
	if(p<=mid)update(ls[x],l,mid,p,v);
	else update(rs[x],mid+1,r,p,v);
}
int querys(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return sum[x];
	if(L<=mid)
		if(mid<R)return querys(ls[x],l,mid,L,R)+querys(rs[x],mid+1,r,L,R);
		else return querys(ls[x],l,mid,L,R);
	else return querys(rs[x],mid+1,r,L,R);
}
int querym(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return mul[x];
	if(L<=mid)
		if(mid<R)return 1ll*querym(ls[x],l,mid,L,R)*querym(rs[x],mid+1,r,L,R)%mod;
		else return querym(ls[x],l,mid,L,R);
	else return querym(rs[x],mid+1,r,L,R);
}
#undef mid
void DFS(int x){
	int w=val[x];
	while(w!=1)update(rt[x],1,m,smax[d[w]-1]+pd[w],PD[w]),w/=PD[w];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		rt[dis[i]]=rt[x];
		DFS(dis[i]);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])x=y;return x;
}
int main(){
	mul[0]=1;
	int n=gi(),u,v;
	for(int i=1;i<n;++i)u=gi(),v=gi(),link(u,v),link(v,u);
	for(int i=1;i<=n;++i)val[i]=gi();
	for(int i=2;i<=N;++i){
		if(!yes[i]){
			pr[++P]=i;d[i]=P;pd[i]=1;PD[i]=i;
			ll x=i;while(x<=N)++max[P],x*=i;
			smax[P]=max[P]+smax[P-1];
		}
		for(int j=1;j<=P&&i*pr[j]<=N;++j){
			yes[i*pr[j]]=1;d[i*pr[j]]=j;
			if(i%pr[j]==0){
				PD[i*pr[j]]=PD[i]*pr[j];
				pd[i*pr[j]]=pd[i]+1;
				break;
			}
			PD[i*pr[j]]=pr[j];
			pd[i*pr[j]]=1;
		}
	}
	m=smax[P];
	dfs(1),dfs(1,1);
	DFS(1);
	int W;
	int q=gi();
	while(q--){
		u=gi(),v=gi(),W=gi();
		int ans=1,lca=LCA(u,v),o,L,R;
		while(W!=1){
			if(pd[W]<max[d[W]]){
				L=smax[d[W]-1]+pd[W]+1,R=smax[d[W]-1]+max[d[W]];
				o=querys(rt[u],1,m,L,R)+querys(rt[v],1,m,L,R)-querys(rt[lca],1,m,L,R);
				if(lca!=1)o-=querys(rt[fa[lca]],1,m,L,R);
				ans=1ll*ans*pow(PD[W],o)%mod;
			}
			L=smax[d[W]-1]+1,R=smax[d[W]-1]+pd[W];
			ans=1ll*ans*querym(rt[u],1,m,L,R)%mod*querym(rt[v],1,m,L,R)%mod;
			o=querym(rt[lca],1,m,L,R);
			if(lca!=1)o=1ll*o*querym(rt[fa[lca]],1,m,L,R)%mod;
			ans=1ll*ans*pow(o,mod-2)%mod;
			W/=PD[W];
		}
		printf("%d\n",ans);
		
	}
	return 0;
}