#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
const u32 P=1e9+7;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}
u64 power(u64 a, u32 b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b%2==1) ans=ans*a%P;
	return ans;
}

const int N=1501;
u32 p[N], psum[N][N], fl[N][N], fr[N][N], s[N];
int main() {
	int n, m, a, b, k;
	u32 pr, q;
	std::cin>>n>>m>>a>>b>>k;
	pr=a*power(b, P-2)%P;
	q=1;
	for(int i=0; i<m&&i<=k; ++i) {
		p[i]=q*power(pr, i)%P*power(dif(1, pr), k-i)%P;
		q=q*power(i+1, P-2)%P*(k-i)%P;
	}
	for(int l=m; l--; ) {
		for(int r=l+1; r<=m; ++r) psum[l][r]=(psum[l][r-1]+(u64)p[l]*p[m-r])%P;
		for(int r=1; r<=m; ++r) inc(psum[l][r], psum[l+1][r]);
	}
	for(int j=0; j<m; ++j) fl[1][j]=psum[j][m];
	for(int j=1; j<=m; ++j) fr[1][j]=psum[0][j];
	s[1]=fr[1][m];
	for(int i=2; i<=n; ++i) {
		u32 cur=0;
		for(int j=m; j--; ) {
			cur=(cur+(u64)p[m-j-1]*fl[i-1][j+1])%P;
			fl[i][j]=(fl[i][j+1]+(u64)(P+psum[j][m]-psum[j+1][m])*(P+s[i-1]-fr[i-1][j])+(u64)(P-p[j])*cur)%P;
		}
		cur=0;
		for(int j=1; j<=m; ++j) {
			cur=(cur+(u64)p[j-1]*fr[i-1][j-1])%P;
			fr[i][j]=(fr[i][j-1]+(u64)(P+psum[0][j]-psum[0][j-1])*(P+s[i-1]-fl[i-1][j])+(u64)(P-p[m-j])*cur)%P;
		}
		s[i]=fr[i][m];
	}
	printf("%u\n", s[n]);
	return 0;
}