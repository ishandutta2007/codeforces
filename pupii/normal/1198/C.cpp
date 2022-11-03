#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int n,m;
int fir[300010],dis[1000010],nxt[1000010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int A[500010],B[500010];
bool vis[500010]={0};
int ans[300010],o;
il vd solve1(){
	puts("IndSet");
	memset(vis+1,0,3*n);
	for(int i=1;i<=o;++i)vis[A[ans[i]]]=vis[B[ans[i]]]=1;
	o=0;
	for(int i=1;i<=3*n;++i)if(!vis[i]&&o<n)ans[++o]=i;
}
il bool solve2(){
	memset(vis+1,0,m);o=0;
	for(int i=1;i<=m;++i){
		if(vis[i])continue;
		ans[++o]=i;if(o==n)break;
		for(int j=fir[A[i]];j;j=nxt[j])vis[j>>1]=1;
		for(int j=fir[B[i]];j;j=nxt[j])vis[j>>1]=1;
	}
	return o==n;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T=gi();
	srand(time(NULL));
	while(T--){
		id=1;
		n=gi(),m=gi();int a,b;
		for(int i=1;i<=m;++i)a=A[i]=gi(),b=B[i]=gi(),link(a,b),link(b,a);
		if(!solve2())solve1();
		else puts("Matching");
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);puts("");
		memset(fir+1,0,12*n);
	}
	return 0;
}