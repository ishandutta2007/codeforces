#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 3605

const LL mod=998244353;
LL n,m,p,q,c[2][N],f[2][N][N],fac[N],ifac[N],ans;
bool vis[2][N];

void upd(LL &x,LL y){x=(x+y)%mod;}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){return x<y||y<0?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

int main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for (LL i=1;i<=q;++i){
		LL xa,ya,xb,yb; scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
		if (xa==xb){
			c[0][yb]=1;
			++c[0][0];
			vis[0][ya]=vis[0][yb+1]=vis[1][xa]=vis[1][xa+1]=1;
		}
		else{
			c[1][xb]=1;
			++c[1][0];
			vis[1][xa]=vis[1][xb+1]=vis[0][ya]=vis[0][ya+1]=1;
		}
	}
	p=max(n,m);
	fac[0]=1; for (LL i=1;i<=p;++i) fac[i]=fac[i-1]*i%mod;
	ifac[p]=inv(fac[p]); for (LL i=p-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL op:{0,1}){
		LL len=op?n:m;
		f[op][0][0]=1;
		for (LL i=1;i<=len;++i){
			for (LL j=0;j<=i/2;++j){
				if (i>1&&!vis[op][i]){
					upd(f[op][i][j],f[op][i-2][j-1]);
				}
				if (!c[op][i]){
					upd(f[op][i][j],f[op][i-1][j]);
				}
			}
		}
	}
	for (LL i=c[0][0];i*2<=m;++i){
		for (LL j=c[1][0];j*2<=n;++j){
			upd(ans,f[0][m][i]*f[1][n][j]%mod*C(n-j*2-c[0][0],i-c[0][0])%mod*fac[i-c[0][0]]%mod*C(m-i*2-c[1][0],j-c[1][0])%mod*fac[j-c[1][0]]);
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}