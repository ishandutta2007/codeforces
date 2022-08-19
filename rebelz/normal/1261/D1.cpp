#include<bits/stdc++.h>

#define y1 dmytxdy
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

const int cys=998244353;
int n,k,m;
ll fac[200005],inv[200005],pw[200005],pwk[200005],h[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint();
	fac[0]=inv[0]=pw[0]=pwk[0]=1;
	for(int i=1;i<=n;i++) pw[i]=mod(pw[i-1]<<1);
	for(int i=1;i<=n;i++) pwk[i]=pwk[i-1]*(k-2)%cys;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n;i++) h[i]=readint();
	h[n+1]=h[1];
	for(int i=1;i<=n;i++) m+=(h[i]!=h[i+1]);
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll now=pw[i];
		if(i%2==0) now=mod(now+cys-fac[i]*inv[i/2]%cys*inv[i/2]%cys);
		now=now*((cys+1)/2)%cys;
		ans=mod(ans+pwk[m-i]*now%cys*fac[m]%cys*inv[m-i]%cys*inv[i]%cys);
	}
	printf("%lld\n",ans*qpow(k,n-m)%cys);
	return 0;
}