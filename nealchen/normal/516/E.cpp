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

const int N=2e5;
std::vector<int> b[N], g[N];
int gcd(int x, int y) {return y?gcd(y, x%y):x;}
std::pair<int, int> exgcd(int x, int y) {
	if(y==0) return {1, 0};
	int a, b;
	std::tie(b, a)=exgcd(y, x%y);
	return {a, b-x/y*a};
}
void gg() {
	puts("-1");
	exit(0);
}
s64 solve(int n, int m, const std::vector<int> &b, const std::vector<int> &g) {
	s64 ans=-1;
	std::vector<std::pair<int, int>> pos;
	int inv=exgcd(n, m).second%n;
	if(inv<0) inv+=n;
	for(int i: b) pos.emplace_back((s64)i*inv%n, 0);
	for(int i: g) pos.emplace_back((s64)i*inv%n, 1);
	std::sort(pos.begin(), pos.end());
	pos.resize(std::unique(pos.begin(), pos.end(), [](std::pair<int, int> p, std::pair<int, int> q) {return p.first==q.first;})-pos.begin());
	int i=pos.back().first;
	for(auto p: pos) {
		if((p.first-1+n)%n!=i) cmax(ans, (s64)(p.first-i-1+n)%n*m+(s64)i*m%n);
		if(p.second) cmax(ans, (s64)i*m%n);
		i=p.first;
	}
	return ans;
}
int main() {
	int n, m, d;
	s64 ans=0;
	std::vector<int> glob, glog;
	n=rd(), m=rd(), d=gcd(n, m);
	glob.resize(rd());
	for(int &i: glob) i=rd();
	glog.resize(rd());
	for(int &i: glog) i=rd();
	if(glob.size()+glog.size()<d) gg();
	for(int i: glob) b[i%d].push_back(i/d);
	for(int i: glog) g[i%d].push_back(i/d);
	n/=d, m/=d;
	for(int i=0; i<d; ++i) {
		if(b[i].empty()&&g[i].empty()) gg();
		cmax(ans, std::max(solve(n, m, b[i], g[i]), solve(m, n, g[i], b[i]))*d+i);
	}
	printf("%lld\n", ans);
	return 0;
}