#include<algorithm>
#include<cstdio>
#include<cstring>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
int n,a[1000001],I[1000001],siz[1000001];
inline bool cmp(int p1,int p2){return a[p1]<a[p2];}
int h[1000001],nxt[2000001],to[2000001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
bool vis[1000001];
int fa[1000001];
int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
long long ans;
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), I[i]=i;
	int x,y,u; long long tmp;
	F2(i,1,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	std::sort(I+1,I+n+1,cmp);
	F(i,1,n){
		siz[u=I[i]]=1; tmp=0; vis[u]=1;
		eF(j,u)
			if(vis[to[j]]) siz[u]+=siz[ff(to[j])], tmp+=1ll*siz[ff(to[j])]*siz[ff(to[j])], fa[ff(to[j])]=u;
		ans+=a[u]*(1ll*siz[u]*siz[u]-tmp);
	}
	memset(fa,0,sizeof fa);
	dF(i,n,1){
		siz[u=I[i]]=1; tmp=0; vis[u]=0;
		eF(j,u)
			if(!vis[to[j]]) siz[u]+=siz[ff(to[j])], tmp+=1ll*siz[ff(to[j])]*siz[ff(to[j])], fa[ff(to[j])]=u;
		ans-=a[u]*(1ll*siz[u]*siz[u]-tmp);
	}
	printf("%lld",ans>>1);
	return 0;
}