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
const u32 P=1e9+7;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}

const int N=2003;
int n, m;
u32 base[N], sh[2][N], WH[N], WRH[N], *wh[2]={WH, WRH}, f[N][2][N], ans;
char s[2][N], W[N], WR[N], *w[2]={W, WR};
u32 gethash(u32 *hash, int l, int r) {return ((u64)hash[l]*(P-base[r-l])+hash[r])%P;}
int left(int l, int r, int c) {
	return (l==1&&s[r][c-1]==w[0][0]) ||
		(l%2==0 &&
		 c>=l/2 &&
		 gethash(sh[!r], c-l/2, c)==gethash(wh[1], m-l/2, m) &&
		 gethash(sh[r], c-l/2, c)==gethash(wh[0], l/2, l)
		);
}
int right(int l, int r, int c) {
	return (m-l==1&&s[r][c]==w[0][l]) ||
		((m-l)%2==0 &&
		 c+(m-l)/2<=n &&
		 gethash(sh[r], c, c+(m-l)/2)==gethash(wh[0], l, (m+l)/2) &&
		 gethash(sh[!r], c, c+(m-l)/2)==gethash(wh[1], 0, (m-l)/2)
		);
}
void sol() {
	if(m%2==0) {
		for(int c=1; c<=n; ++c) inc(ans, left(m, 0, c));
		if(m>2) for(int c=0; c<n; ++c) inc(ans, right(0, 0, c));
	}
	for(int l=1; l<m; ++l)
		for(int r=0; r<2; ++r)
			for(int c=1; c<=n; ++c) {
				u32 &F=f[l][r][c];
				F=left(l, r, c);
				if(s[r][c-1]==w[0][l-1]) {
					inc(F, f[l-1][r][c-1]);
					if(l>=2&&s[!r][c-1]==w[0][l-2]) inc(F, f[l-2][!r][c-1]);
				}
				if(right(l, r, c)) inc(ans, F);
			}
}
int main() {
	assert(scanf("%s%s%s", s[0], s[1], w[0])==3);
	n=strlen(s[0]), m=strlen(w[0]);
	if(m==1) {
		int cnt=0;
		for(int i=0; i<2; ++i) for(int j=0; j<n; ++j) cnt+=s[i][j]==w[0][0];
		printf("%d\n", cnt);
		return 0;
	}
	std::reverse_copy(w[0], w[0]+m, w[1]);
	base[0]=1;
	for(int i=1; i<=n||i<=m; ++i) base[i]=base[i-1]*131llu%P;
	for(int i=0; i<2; ++i) for(int j=0; j<n; ++j) sh[i][j+1]=(sh[i][j]*131llu+s[i][j])%P;
	for(int i=0; i<2; ++i) for(int j=0; j<m; ++j) wh[i][j+1]=(wh[i][j]*131llu+w[i][j])%P;
	sol();
	std::swap(w[0], w[1]);
	std::swap(wh[0], wh[1]);
	sol();
	printf("%u\n", ans);
	return 0;
}