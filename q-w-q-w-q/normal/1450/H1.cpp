#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,x,s,ans;
char a[200001];
int fac[200001],ifac[200001];
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
int main(){
	scanf("%d%d%s",&n,&m,a+1);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	for(int i=n-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	x=n>>1;
	for(int i=1;i<=n;i++){
		if(a[i]=='w'&&i%2==1) x--;
		if(a[i]=='b'&&i%2==0) x--;
		if(a[i]=='?') s++;
	}
	for(int i=x&1;i<=s;i+=2) ans=(ans+1ll*abs(x-i)*fac[s]%mod*ifac[i]%mod*ifac[s-i])%mod;
	cout<<1ll*ans*power(2,1ll*s*(mod-2)%(mod-1))%mod;
}