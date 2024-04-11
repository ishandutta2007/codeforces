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
//const int P=;
//inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
//inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
//inline int add(int a, int b) {return (a+=b)<P?a:a-P;}
//inline int sub(int a, int b) {return (a-=b)<0?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

const int N=2e5+5;
int n;
s64 a[N], st[18][N], *d=st[0];
s64 gcd(s64 a, s64 b) {
	return b?gcd(b, a%b):a;
}
bool check(int l, int r) {
	int lv=31^__builtin_clz(r-l);
	return gcd(st[lv][l], st[lv][r-(1<<lv)])!=1;
}
void work() {
	n=rd();
	std::generate(a, a+n, read<s64>);
	for(int i=1; i<n; ++i) {
		d[i]=a[i]-a[i-1];
		if(d[i]<0) d[i]=-d[i];
	}
	for(int i=1; (1<<i)<n; ++i) {
		for(int j=1; j+(1<<i)<=n; ++j)
			st[i][j]=gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
	}
	int ans=0;
	for(int l=1, r=1; r<=n; ++r) {
		while(l<r && !check(l, r)) ++l;
		ans=std::max(ans, r-l+1);
	}
	printf("%d\n", ans);
}
int main() {
	int t=rd();
	while(t--) work();
	return 0;
}