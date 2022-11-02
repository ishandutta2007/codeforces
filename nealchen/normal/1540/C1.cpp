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

const int N=101;
int n, c[N], b[N], g[N*N], ans[N];
int main() {
	n=rd();
	for(int i=1; i<=n; ++i) c[i]=rd();
	for(int i=2; i<=n; ++i) b[i]=b[i-1]+rd();
	for(int i=2; i<=n; ++i) b[i]+=b[i-1];
	for(int i=1; i<=n; ++i) meow("%d%c", b[i], " \n"[i==n]);
	int Qmin=1e9, Qmax=1e9;
	for(int i=1, s=0; i<=n; ++i) {
		s+=c[i];
		Qmin=std::min(Qmin, (int)floor(-1.0*b[i]/i));
		Qmax=std::min(Qmax, (int)floor(1.0*(s-b[i])/i));
	}
	for(int x=Qmin; x<=Qmax; ++x) {
		g[0]=1;
		int max=0;
		for(int i=1; i<=n; ++i) {
			int min=std::max(0, b[i]+i*x);
			for(int j=max+1; j<=max+c[i]; ++j) g[j]=g[j-1];
			max+=c[i];
			for(int j=max; j>c[i]; --j) dec(g[j], g[j-c[i]-1]);
			memset(g, 0, min*sizeof(int));
			for(int j=1; j<=max; ++j) inc(g[j], g[j-1]);
		}
		ans[x-Qmin]=g[max];
	}
	int q=rd();
	while(q--) {
		int x=rd();
		printf("%d\n", x>Qmax?0:ans[std::max(0, x-Qmin)]);
	}
	return 0;
}