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

s64 first(s64 x) {
	int group=(63-__builtin_clzll(x*3+1))/2;
	x-=((1ll<<2*group)-1)/3;
	return (1ll<<2*group)+x;
}
s64 second(s64 x) {
	int group=(63-__builtin_clzll(x*3+1))/2, replace[]={0, 2, 3, 1};
	x-=((1ll<<2*group)-1)/3;
	for(int i=0; i<group; ++i) {
		int d=x>>(2*i)&3;
		x^=s64(d^replace[d])<<(2*i);
	}
	return (1ll<<2*group+1)+x;
}
int main() {
	int t=rd();
	while(t--) {
		s64 n=read<s64>()-1, a[3]={first(n/3), second(n/3)};
		a[2]=a[0]^a[1];
		printf("%lld\n", a[n%3]);
	}
	return 0;
}