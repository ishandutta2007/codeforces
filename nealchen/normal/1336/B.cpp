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

const int N=1e5;
int x[3][N];
long long f(long long x, long long y, long long z) {
	return 2*(x*x+y*y+z*z-x*y-y*z-z*x);
}
void work() {
	int n[3];
	long long ans=5e18;
	std::generate(n, n+3, rd);
	for(int i=0; i<3; ++i) {
		std::generate(x[i], x[i]+n[i], rd);
		std::sort(x[i], x[i]+n[i]);
	}
	for(int i=0; i<3; ++i) {
		int u=(i+1)%3, v=(i+2)%3;
		for(int tick=0; tick<2; ++tick) {
			for(int j=0; j<n[i]; ++j) {
				int t=x[i][j], *p, *q;
				p=std::lower_bound(x[u], x[u]+n[u], t);
				q=std::upper_bound(x[v], x[v]+n[v], t);
				if(p!=x[u]+n[u]&&q!=x[v]) cmin(ans, f(t, *p, q[-1]));
			}
			std::swap(u, v);
		}
	}
	printf("%lld\n", ans);
}
int main() {
	int t=rd();
	while(t--) work();
	return 0;
}