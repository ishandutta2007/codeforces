#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef unsigned long long u64;
const u32 P=1e6+3;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return inc(a, b);}
inline u32 dif(u32 a, u32 b) {return dec(a, b);}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
u64 power(u64 a, u32 b) {
	u64 ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}
int main() {
	u64 n=read<u64>(), k=read<u64>();
	if(n<64&&k>1llu<<n) {
		std::cout<<"1 1"<<std::endl;
	} else {
		u64 num2=0, num, den, fir;
		for(int a=1; 1llu<<a<k; ++a) num2=(num2+(k-1>>a))%(P-1);
		num=power(2, num2?P-1-num2:0);
		fir=power(2, n%(P-1));
		den=num*power(fir, (k-1)%(P-1))%P;
		if(k>=P) {
			std::cout<<den<<" "<<den<<std::endl;
		} else {
			for(int a=1; a<k; ++a) num=num*dif(fir, a)%P;
			std::cout<<dif(den, num)<<" "<<den<<std::endl;
		}
	}
	return 0;
}