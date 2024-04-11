#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007,inv2=(cys+1)/2;
ll n,T,ans;
ll fac[200005],inv[200005],a[200005],s[200005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); T=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n;i++) a[i]=readint(),s[i]=s[i-1]+a[i];
	ll nw=n,nm=0,res=1;
	for(int i=1;i<=n;i++){
		ll x=min(n,T-s[i]);
		if(x<0) break;
		while(nw>x) res=mod(res+cys-C(nm,nw)),nw--;
		while(nm<i) res=mod(mod(res<<1)+cys-C(nm,nw)),nm++;
		ans=mod(ans+res*qpow(inv2,i)%cys);
	}
	cout<<ans<<endl;
	return 0;
}