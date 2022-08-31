#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
ll n,m,a,b,ans=0;
ll fac[1000005],inv[1000005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

ll C(ll x,ll y){
	if(x<y) return 0;
	return fac[x]*inv[y]%cys*inv[x-y]%cys;
}

int main(){
	n=readint(); m=readint(); a=readint(); b=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=max(n,m)+3;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=max(n,m)+3;i++) inv[i]=qpow(fac[i],cys-2);
	for(int i=1;i<=min(n-1,m);i++){
		ll now=C(n-2,i-1)*fac[i-1]%cys*C(m-1,i-1)%cys*qpow(m,n-i-1)%cys;
		if(i!=n-1) now=now*(i+1)%cys*qpow(n,n-i-2)%cys;
		ans=(ans+now)%cys;
	}
	cout<<ans<<endl;
	return 0;
}