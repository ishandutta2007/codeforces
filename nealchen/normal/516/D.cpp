#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
//const u32 P=;
//inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
//inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}
const int N=1e5+1;
int n, head[N], next[2*N], to[2*N], w[N], queue[N], fa[N], rank[N], size[N];
s64 dis[N], save[N];
int measure(int x) {
	int *h=queue, *t=queue, cho=x;
	s64 max=0;
	memset(dis+1, -1, n*sizeof(s64));
	dis[*t++=x]=0;
	while(h!=t) {
		x=*h++;
		if(cmax(max, dis[x])) cho=x;
		for(int i=head[x]; i; i=next[i])
			if(dis[to[i]]==-1) dis[*t++=to[i]]=dis[x]+w[i/2];
	}
	return cho;
}
int find(int x) {return fa[x]==x?x:(fa[x]=find(fa[x]));}
void join(int x, int y) {
	x=find(x), y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]) {
		fa[x]=y;
		size[y]+=size[x];
	} else {
		fa[y]=x;
		size[x]+=size[y];
		rank[x]+=(rank[x]==rank[y]);
	}
}
int main() {
	n=rd();
	for(int i=1, j=2; i<n; ++i) {
		int u=rd(), v=rd();
		w[i]=rd();
		to[j]=v, next[j]=head[u], head[u]=j++;
		to[j]=u, next[j]=head[v], head[v]=j++;
	}
	int a=measure(1), b=measure(a);
	memcpy(save+1, dis+1, n*sizeof(s64));
	measure(b);
	for(int i=1; i<=n; ++i) cmax(dis[i], save[i]);
	for(int i=0; i<n; ++i) queue[i]=i+1;
	std::sort(queue, queue+n, [](int x, int y) {return dis[x]<dis[y];});
	for(int q=rd(); q--; ) {
		s64 l=read<s64>();
		int ans=0;
		memset(fa+1, 0, n*sizeof(int));
		memset(rank+1, 0, n*sizeof(int));
		for(int i=n, j=n-1; i--; ) {
			int x=queue[i], y;
			fa[x]=x, size[x]=1;
			for(int e=head[x]; e; e=next[e]) if(fa[to[e]]) join(x, to[e]);
			for(; j>=i&&dis[y=queue[j]]>dis[x]+l; --j) --size[find(y)];
			cmax(ans, size[find(x)]);
		}
		printf("%d\n", ans);
	}
	return 0;
}