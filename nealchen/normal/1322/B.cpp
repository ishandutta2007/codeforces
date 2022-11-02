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

const int N=4e5;
int n, a[N], b[N];
int main() {
	int ans=0;
	n=rd(), std::generate(a, a+n, rd);
	for(int i=0; i<25; ++i) {
		int tot=0, bit=0;
		for(int j=0; j<n; ++j) b[j]=a[j]&((1<<i)-1);
		for(int j=0; j<n; ++j) bit+=a[j]>>i&1;
		bit=bit&(n-bit)&1;
		for(int j=0, k=n; k--; ) {
			while(j<k&&b[j]+b[k]<(1<<i)) ++j;
			if(j==k) break;
			bit^=k-j&1;
		}
		ans^=bit<<i;
		for(int j=0; j<n; ++j) if(~a[j]>>i&1) b[tot++]=a[j];
		for(int j=0; j<n; ++j) if(a[j]>>i&1) b[tot++]=a[j];
		std::copy(b, b+n, a);
	}
	printf("%d\n", ans);
	return 0;
}