#include <stdio.h>
#include <algorithm>
#define MN 200000
#define MM 200000
typedef long long LL;
int n,m,fa[MN+5];
LL a[MN+5],mi=0x7fffffffffffffff,ans=0;
struct EDGE{int u,v;LL w;}e[MM+MN+5]; int ec=0;
bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}
int gf(int u){
	if(fa[u]==u) return u;
	else return fa[u]=gf(fa[u]);
}
bool unite(int u,int v){
	u=gf(u),v=gf(v);
	if(u==v) return false;
	fa[v]=u;
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mi=std::min(mi,a[i]);
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		static int u,v;
		static LL w;
		scanf("%d%d%lld",&u,&v,&w);
		w=std::min(w,a[u]+a[v]);
		if(w+std::min(a[u],a[v])<=a[u]+a[v]+mi)
			e[++ec]=(EDGE){u,v,w};
	}
	for(int i=1;i<=n;i++)
		e[++ec]=(EDGE){0,i,a[i]+mi};
	std::sort(e+1,e+1+ec,cmp);
	for(int i=1;i<=ec;i++)
		if(unite(e[i].u,e[i].v))
			ans+=e[i].w;
	printf("%lld\n",ans-mi*2);
}