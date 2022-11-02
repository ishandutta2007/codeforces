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

int n, m, d[10000], g, r, q[2][10010000], len[2], ans[10010000];
int main() {
	n=rd();
	m=rd();
	std::generate(d, d+m, rd);
	std::sort(d, d+m);
	m=std::unique(d, d+m)-d;
	g=rd();
	r=rd();
	q[0][len[0]++]=0;
	memset(ans, 63, m*(g+1)*sizeof(int));
	ans[0]=0;
	for(int k=0, t=0; len[k]; ++t, k^=1) {
		len[k^1]=0;
		for(int i=0; i<len[k]; ++i) {
			int u=q[k][i], x=u/(g+1), y=u%(g+1);
			if(ans[u]!=t) continue;
			if(x==m-1) {
				printf("%lld\n", y+1ll*(g+r)*t);
				return 0;
			}
			if(y==g) {
				int v=x*(g+1);
				if(t+1<ans[v]) {
					ans[v]=t+1;
					q[k^1][len[k^1]++]=v;
				}
				continue;
			}
			if(x>0) {
				int yy=y+d[x]-d[x-1];
				if(yy<=g) {
					int v=(x-1)*(g+1)+yy;
					if(t<ans[v]) {
						ans[v]=t;
						q[k][len[k]++]=v;
					}
				}
			}
			if(x<m-1) {
				int yy=y+d[x+1]-d[x];
				if(yy<=g) {
					int v=(x+1)*(g+1)+yy;
					if(t<ans[v]) {
						ans[v]=t;
						q[k][len[k]++]=v;
					}
				}
			}
		}
	}
	puts("-1");
	return 0;
}