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
const int P=1e9+7;
inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
inline int add(int a, int b) {return (a+=b)<P?a:a-P;}
inline int sub(int a, int b) {return (a-=b)<0?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=3e6+5;
int n, x, fac[N], ifac[N], a[N], b[N], c[N];
void init(int m) {
	fac[0]=1;
	for(int i=1; i<=m; ++i) fac[i]=1llu*fac[i-1]*i%P;
	ifac[m]=power(fac[m], P-2);
	for(int i=m; i>=1; --i) ifac[i-1]=1llu*ifac[i]*i%P;
}
u64 com(int n, int r) {
	return 1llu*fac[n]*ifac[r]%P*ifac[n-r]%P;
}
int main() {
	scanf("%d", &n);
	init(3*n+1);
	a[0]=b[0]=c[0]=n;
	u64 inv3=(P+1)/3;
	for(int i=1; i<=3*n; ++i) {
		a[i]=(com(3*n+1, i+1)+2*b[i-1]+c[i-1])*inv3%P;
		b[i]=sub(a[i], b[i-1]);
		c[i]=sub(b[i], c[i-1]);
	}
	int q=rd();
	while(q--) printf("%d\n", a[rd()]);
	return 0;
}