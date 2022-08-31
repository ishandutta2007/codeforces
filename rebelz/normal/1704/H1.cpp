// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,cys;
ll fac[1000005],inv[1000005],pw[1000005],pw0[5005][5005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); cys=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*(n-1)%cys;
	for(int i=0;i<=n;i++){
		pw0[i][0]=1;
		for(int j=1;j<=n;j++) pw0[i][j]=pw0[i][j-1]*i%cys;
	}
	if(n==1) return printf("0\n"),0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-2*i;j++){
			ll tmp=fac[n]*inv[i]%cys*inv[j]%cys;
			tmp=tmp*C(n-i-j-1,i-1)%cys;
			tmp=tmp*pw[i]%cys;
			tmp=tmp*pw0[n-i-j][j]%cys;
			ans=mod(ans+tmp);
		}
	}
	printf("%lld\n",ans);
	return 0;
}