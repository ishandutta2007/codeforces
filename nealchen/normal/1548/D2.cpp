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
const int P=4;
inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
inline int add(int a, int b) {return (a+=b)<P?a:a-P;}
inline int sub(int a, int b) {return (a-=b)<0?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=6005;
int n, x[N], y[N], cnt[64];
int gcd(int x, int y) {
	return y?gcd(y, x%y):x;
}
int main() {
	n=rd();
	for(int i=1; i<=n; ++i) x[i]=rd(), y[i]=rd();
	s64 ans=0;
	for(int i=1; i<=n; ++i) {
		memset(cnt, 0, sizeof(cnt));
		for(int j=1; j<=n; ++j) {
			if(i==j) continue;
			int dd = gcd(abs(x[j]-x[i]), abs(y[j]-y[i])) % 4;
			int xx = (x[j]-x[i]) & 3;
			int yy = (y[j]-y[i]) & 3;
			++cnt[dd << 4 | xx << 2 | yy];
		}
		for(int j=0; j<64; ++j) {
			if(!cnt[j]) continue;
			int jd=j>>4, jx=j>>2&3, jy=j&3;
			for(int k=j; k<64; ++k) {
				if(!cnt[k]) continue;
				int kd=k>>4, kx=k>>2&3, ky=k&3;
				if(jd%2!=kd%2) continue;
				int dd=gcd(abs(jx-kx), abs(jy-ky))%4;
				if(dd%2!=0) continue;
				if(abs(jx*ky-jy*kx)%4==(jd+kd+dd)%4)
					ans+=(j==k ? cnt[j]*(cnt[j]-1)/2 : cnt[j]*cnt[k])*(jd%2==0 ? 1 : 3);
			}
		}
	}
	printf("%lld\n", ans/3);
	return 0;
}