#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

const int N=1e5, M=1e6+1;
int n, v[N], suf[M];
std::pair<int, int> s[N];
int main() {
	s64 tot=0;
	n=rd();
	tot=(s64)n*n;
	for(int i=0; i<n; ++i) {
		int l=rd();
		bool ok=true;
		for(int i=0; i<l; ++i) v[i]=rd();
		for(int i=1; i<l; ++i) ok&=v[i-1]>=v[i];
		if(ok) s[i]={v[0], v[l-1]}; else --i, --n;
	}
	for(int i=0; i<n; ++i) ++suf[s[i].second];
	for(int i=1e6; i--; ) suf[i]+=suf[i+1];
	for(int i=0; i<n; ++i) tot-=suf[s[i].first];
	printf("%lld\n", tot);
	return 0;
}