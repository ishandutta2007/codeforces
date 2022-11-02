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

const int N=5e5+5;
u64 hash[N], qaq[N];
s64 c[N], s[N];
std::unordered_map<u64, int> map;
s64 gcd(s64 a, s64 b) {return b?gcd(b, a%b):a;}
void work() {
	int n=rd(), m=rd(), tot=0;
	std::mt19937_64 gen(rand());
	for(int i=1; i<=n; ++i) hash[i]=gen();
	for(int i=1; i<=n; ++i) c[i]=read<s64>();
	for(int i=1; i<=n; ++i) qaq[i]=0;
	for(int i=1; i<=m; ++i) {
		int x=rd(), y=rd();
		qaq[y]^=hash[x];
	}
	map.clear();
	for(int i=1; i<=n; ++i) {
		if(qaq[i]==0) continue;
		auto it=map.find(qaq[i]);
		if(it==map.end()) {
			s[tot]=c[i];
			map.emplace(qaq[i], tot++);
		} else {
			s[it->second]+=c[i];
		}
	}
	s64 res=0;
	for(int i=0; i<tot; ++i) res=gcd(res, s[i]);
	printf("%lld\n", res);
}
int main() {
	srand(std::chrono::steady_clock::now().time_since_epoch().count());
	int t=rd();
	while(t--) work();
	return 0;
}