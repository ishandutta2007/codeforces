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

const int N=2005;
int n, m, l[N], s[N], c[2*N], pre[N], ans;
std::vector<int> f[N];
int main() {
	n=rd(), m=rd();
	for(int i=0; i<n; ++i) l[i]=rd();
	for(int i=0; i<n; ++i) s[i]=rd();
	for(int i=1; i<=n+m; ++i) c[i]=rd(), pre[i]=c[i]+pre[i-1];
	for(int i=1; i<=m; ++i) f[i]={0};
	for(int i=n; i--; ) {
		auto &F=f[l[i]];
		int sz=F.size();
		F.push_back(-1e9);
		for(int j=sz; j--; ) {
			cmax(F[j+1], F[j]+pre[__builtin_ctz(j+1)+l[i]]-pre[l[i]-1]-s[i]);
			cmax(ans, F[j+1]);
		}
		for(int j=l[i]; j<m; ++j, sz/=2) {
			if(sz/2>=f[j+1].size()) f[j+1].resize(sz/2+1, -1e9);
			for(int k=0; k<=sz; ++k) cmax(f[j+1][k/2], f[j][k]);
		}
	}
	printf("%d\n", ans);
	return 0;
}