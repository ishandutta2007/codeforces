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
const int N=1e7+1;
int cnt[N], times[N], mu[N], fs[N];
bool vis[N];
int main() {
	int n=rd(), max=0;
	u32 ans=0;
	for(int i=0; i<n; ++i) {
		int a=rd();
		cmax(max, a);
		++cnt[a];
	}
	mu[1]=1;
	for(int i=2; i<=max; ++i) if(!vis[i])
		for(int j=max/i, t=i*j; j>=1; --j, t-=i) {
			vis[t]=true;
			mu[t]=(j%i==0)?0:-mu[j];
			cnt[j]+=cnt[t];
		}
	for(int i=1; i<=n; ++i) {
		fs[i]=fs[i-1]*2+1;
		if(fs[i]>=P) fs[i]-=P;
	}
	for(int i=1; i<=max; ++i)
		if(mu[i]) {
			u32 cur=(u64)(cnt[i]-n+P)*fs[cnt[i]]%P;
			if(mu[i]==1) inc(ans, cur); else dec(ans, cur);
		}
	printf("%u\n", ans);
	return 0;
}