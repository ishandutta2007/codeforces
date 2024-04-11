#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const u32 P=1e9+7;
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}
int p, alpha, n, a[4000];
u32 dp[2][4000][2][2];
char s[1001];
u64 sol(int mx) {
	if(mx<0) return 0;
	if(mx>=p) return (u64)p*p-sol(2*p-3-mx);
	return (mx+1llu)*(mx+2llu)/2;
}
u64 range(int l, int r) {return r<l?0:(sol(r)-sol(l-1))%P;}
int main() {
	u32 ans=0;
	auto f=dp[0], g=dp[1];
	assert(scanf("%d%d%s", &p, &alpha, s)==3);
	n=1;
	for(int i=0; s[i]; ++i) {
		int up=s[i]-48;
		for(int j=1; j<=n; ++j) {
			s64 t=(s64)a[j]*10+up;
			a[j]=t%p;
			up=t/p;
		}
		for(; up; up/=p) a[++n]=up%p;
	}
	std::reverse(a+1, a+n+1);
	f[0][0][1]=1;
	for(int i=1; i<=n; ++i) {
		std::swap(f, g);
		memset(f, 0, (i+1)*sizeof(f[0]));
		for(int j=0; j<i; ++j)
			for(int c=0; c<2; ++c) if(g[j][c][0]||g[j][c][1])
				for(int d=0; d<2; ++d) {
					int o=p*c-d, min=std::max(0, o);
					f[j+c][d][0]=(f[j+c][d][0]+g[j][c][0]*range(min, o+p-1)+g[j][c][1]*range(min, o+a[i]-1))%P;
					if(o+a[i]>=0) f[j+c][d][1]=(f[j+c][d][1]+g[j][c][1]*range(o+a[i], o+a[i]))%P;
				}
	}
	for(int i=alpha; i<=n; ++i) ans=(ans+f[i][0][0]+f[i][0][1])%P;
	printf("%u\n", ans);
	return 0;
}