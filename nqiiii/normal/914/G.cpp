#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
const int mod=1000000007,sz=17,inv=742744451;
inline int add(int x,int y){return (x+y)%mod;}
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1ll*x*y%mod;}
int n,a[1<<sz],b[1<<sz],c[1<<sz],d[1<<sz],e[1<<sz];
int f[1<<sz],g[1<<sz],fib[1<<sz],ans;
void workor(int p,int x){
	if(!x) f[p]=mul(f[p],g[p]);
	else{
		for(int i=p+(1<<x-1);i<p+(1<<x);++i){
			f[i]=add(f[i],f[i-(1<<x-1)]); g[i]=add(g[i],g[i-(1<<x-1)]);
		}
		workor(p,x-1); workor(p+(1<<x-1),x-1);
		for(int i=p+(1<<x-1);i<p+(1<<x);++i) f[i]=dec(f[i],f[i-(1<<x-1)]);
	}
}
void getand(int *x,int *y){
	for(int i=0;i<1<<sz;++i){
		f[i^((1<<sz)-1)]=x[i]; g[i^((1<<sz)-1)]=y[i];
	}
	workor(0,sz);
	for(int i=0;i<1<<sz;++i) x[i^((1<<sz)-1)]=f[i];
}
void workxor(int p,int x){
	if(!x) f[p]=mul(f[p],g[p]);
	else{
		for(int i=p+(1<<x-1);i<p+(1<<x);++i){
			f[i-(1<<x-1)]=add(f[i-(1<<x-1)],f[i]); f[i]=dec(f[i-(1<<x-1)],mul(f[i],2));
			g[i-(1<<x-1)]=add(g[i-(1<<x-1)],g[i]); g[i]=dec(g[i-(1<<x-1)],mul(g[i],2));
		}
		workxor(p,x-1); workxor(p+(1<<x-1),x-1);
		for(int i=p+(1<<x-1);i<p+(1<<x);++i){
			f[i-(1<<x-1)]=add(f[i-(1<<x-1)],f[i]); f[i]=dec(f[i-(1<<x-1)],mul(f[i],2));
		}
	}
}
void getxor(int *x,int *y){
	memcpy(f,x,sizeof f); memcpy(g,y,sizeof g);
	workxor(0,sz);
	for(int i=0;i<1<<sz;++i) x[i]=mul(f[i],inv);
}
int fpow(int a,int b){
	int ans=1;
	for(;b;b/=2,a=mul(a,a)) if(b%2) ans=mul(ans,a);
	printf("%d",ans);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		++b[x]; ++c[x]; ++d[x]; ++e[x];
	}
	for(int i=0;i<1<<sz;++i){
		int t=i^((1<<sz)-1);
		for(int j=t;j;j=(j-1)&t) a[i|j]=add(a[i|j],mul(b[i],c[j]));
		a[i]=add(a[i],mul(b[i],c[0]));
	}
	getxor(d,e);
	for(int i=0;i<1<<sz;++i){
		fib[i]=i?i==1?1:add(fib[i-1],fib[i-2]):0;
		a[i]=mul(a[i],fib[i]); c[i]=mul(c[i],fib[i]); d[i]=mul(d[i],fib[i]);
	}
	getand(a,c); getand(a,d);
	for(int i=0;i<sz;++i) ans=add(ans,a[1<<i]); printf("%d",ans);
}