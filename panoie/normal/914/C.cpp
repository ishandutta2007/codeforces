#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
const int N = 1005, P = 1000000007;
int k, len, g[N];
char s[N];
ll ans, p[N], inv[N], f[N][N];
inline ll Pow(ll x, int y){
	ll ass=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ass=ass*x%P;
	return ass;
}
inline ll C(int x, int y){
	if(y>x) return 0;
	return p[x]*inv[y]%P*inv[x-y];
}
int main() {
	p[0]=1;
	rep(i, 1, 1000) p[i]=p[i-1]*i%P;
	inv[1000]=Pow(p[1000], P-2);
	per(i, 999, 0) inv[i]=inv[i+1]*(i+1)%P;
	scanf("%s%d", s, &k);
	len=strlen(s);
	
	f[len][0]=1;
	per(i, len-1, 0) rep(j, 0, len){
		if(s[i]=='0') f[i][j]=f[i+1][j];
		else f[i][j]=(j?f[i+1][j-1]:0)+C(len-i-1, j);
		f[i][j]%=P;
	}
	
	rep(i, 1, 1000){
		int cnt=0;
		for(rt j=i; j; j^=j&-j) ++cnt;
		g[i]=g[cnt]+1;
		if(g[i]==k) (ans+=f[0][i])%=P;
	}
	if(k==1) --ans;
	printf("%lld", k?ans:1);
	return 0;
}