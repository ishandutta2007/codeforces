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
int (*rd)()=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

int p;
u32 a[131], b[131];
void mul(u32 *a, const u32 *b) {
	u32 c[131];
	memset(c, 0, (p+1)*sizeof(u32));
	for(int i=0; i<=p; ++i)
		for(int j=0; i+j<=p; ++j)
			c[i+j]+=a[i]*b[j];
	memcpy(a, c, (p+1)*sizeof(u32));
}
int main() {
	int n, q;
	u32 ans=0;
	n=rd(), p=std::min(n-1, rd()), q=rd();
	b[0]=1;
	a[0]=a[1]=1;
	for(; n; mul(a, a), n/=2) if(n&1) mul(b, a);
	for(int i=1; i<=q; ++i) {
		u32 cur=0, pw=1;
		for(int j=0; j<=p; ++j, pw*=i) cur+=pw*b[j];
		ans^=i*cur;
	}
	printf("%u\n", ans);
	return 0;
}