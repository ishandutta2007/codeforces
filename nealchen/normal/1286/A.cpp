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
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

int a[101], f[101][101][101][2];
int main() {
	int n;
	n=rd();
	for(int i=1; i<=n; ++i) a[i]=rd();
	memset(f, 63, sizeof(f));
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int i=1; i<=n; ++i)
		for(int v=0; v<2; ++v)
			if(a[i]==0||a[i]%2==v)
				for(int j=(v==0); j<=n; ++j)
					for(int k=(v==1); k<=n; ++k)
						for(int u=0; u<2; ++u)
							cmin(f[i][j][k][v], f[i-1][j-(v==0)][k-(v==1)][u]+(u!=v));
	printf("%d\n", std::min(f[n][n/2][(n+1)/2][0], f[n][n/2][(n+1)/2][1]));
	return 0;
}