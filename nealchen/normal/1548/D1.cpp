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
int n, x[N], y[N], cnt[4][4];
int gcd(int x, int y) {
	return y?gcd(y, x%y):x;
}
int main() {
	n=rd();
	for(int i=1; i<=n; ++i) x[i]=rd()%4, y[i]=rd()%4;
	s64 ans=0;
	for(int i=1; i<=n-2; ++i) {
		memset(cnt, 0, sizeof(cnt));
		for(int j=i+1; j<=n; ++j) ++cnt[sub(x[j], x[i])][sub(y[j], y[i])];
		for(int x1=0; x1<4; ++x1) {
			for(int y1=0; y1<4; ++y1) {
				if(!cnt[x1][y1]) continue;
				for(int x2=x1; x2<4; ++x2) {
					for(int y2=(x1==x2?y1:0); y2<4; ++y2) {
						if(!cnt[x2][y2]) continue;
						int area2=abs(x1*y2-x2*y1), len=gcd(x1, y1)+gcd(x2, y2)+gcd(abs(x1-x2), abs(y1-y2));
						if(area2%2==0 && area2==len%4) {
							if(x1==x2 && y1==y2) {
								ans+=cnt[x1][y1]*(cnt[x1][y1]-1)/2;
							} else {
								ans+=cnt[x1][y1]*cnt[x2][y2];
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}