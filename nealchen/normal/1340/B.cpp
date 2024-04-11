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

const char digit_s[][8]={
	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};
const int N=2001;
int digit[10], d[N], cnt[128];
char s[8], f[N][N], g[N][N], h[N][N];
int main() {
	int n=rd(), k=rd();
	for(int i=1; i<128; ++i) cnt[i]=cnt[i/2]+i%2;
	for(int i=0; i<10; ++i) {
		for(int j=0; j<7; ++j) digit[i]|=(digit_s[i][j]-48)<<j;
	}
	for(int i=0; i<n; ++i) {
		scanf("%s", s);
		for(int j=0; j<7; ++j) d[i]|=(s[j]-48)<<j;
	}
	f[n][0]=1;
	for(int i=n; i--; ) {
		for(int j=0; j<10; ++j) {
			if((d[i]&digit[j])==d[i]) {
				int z=cnt[digit[j]]-cnt[d[i]];
				for(int l=z; l<=k; ++l) {
					if(f[i+1][l-z]) {
						f[i][l]=true;
						g[i][l]=j;
						h[i][l]=z;
					}
				}
			}
		}
	}
	if(!f[0][k]) {
		puts("-1");
		return 0;
	}
	for(int i=0; i<n; ++i) {
		printf("%d", g[i][k]);
		k-=h[i][k];
	}
	puts("");
	return 0;
}