#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cys;
ll fac[405],inv[405],d[405][405],f[405];

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
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i]=(f[i]+fac[i-1]*inv[j-1]%cys*inv[i-j])%cys;
	for(int i=1;i<=n;i++) d[i][i]=f[i]*inv[i]%cys;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			for(int k=3;k<=i;k++)
				if(j-(i-k+1)>=0) d[i][j]=(d[i][j]+d[k-2][j-(i-k+1)]*f[i-k+1]%cys*inv[i-k+1])%cys;
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+d[n][i]*fac[i])%cys;
	printf("%lld\n",ans);
	return 0;
}