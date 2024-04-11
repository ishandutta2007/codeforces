#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
ll n,k,l;
ll fac[10005],ifac[10005],pw[10005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint(); l=readint();
	fac[0]=ifac[0]=pw[0]=1;
	for(int i=1;i<=2*n+1;i++) fac[i]=fac[i-1]*i%cys,pw[i]=pw[i-1]*2%cys;
	ifac[2*n+1]=qpow(fac[2*n+1],cys-2);
	for(int i=2*n;i>=1;i--) ifac[i]=ifac[i+1]*(i+1)%cys;
	ll ans=l*fac[n]%cys,sum=0;
	for(int i=k;i<=n;i++)
		for(int j=0;j<=n-i;j++)
			sum=(sum+ifac[i]*ifac[j]%cys*pw[i+j]%cys*fac[i+j]%cys*fac[i+j]%cys*ifac[2*i+2*j+1]%cys*ifac[n-i-j]%cys*((j&1)?cys-1:1)%cys)%cys;
	printf("%lld\n",ans*sum%cys);
	return 0;
}