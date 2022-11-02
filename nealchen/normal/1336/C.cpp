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
const u32 P=998244353;
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=3005;
u32 f[N][N];
char s[N], t[N];
int main() {
	int n, m;
	u32 ans=0;
	scanf("%s%s", s, t);
	n=strlen(s);
	m=strlen(t);
	for(int i=n; i>=0; --i) {
		f[i][i]=1;
		for(int j=i; j<=n; ++j) {
			char c=s[j-i];
			if(f[i][j]) {
				if(i>0&&(i>m||t[i-1]==c)) inc(f[i-1][j], f[i][j]);
				if(j<n&&(j>=m||t[j]==c)) inc(f[i][j+1], f[i][j]);
			}
		}
	}
	for(int i=m; i<=n; ++i) inc(ans, f[0][i]);
	printf("%u\n", ans);
	return 0;
}