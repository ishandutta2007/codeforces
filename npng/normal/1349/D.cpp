#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=300000;
const int Mod=998244353;
typedef long long ll;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%Mod;
		}
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
int n,s;
int a[Maxn+5];
ll f[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	f[0]=n-1;
	ll invs=qpow(s,Mod-2);
	for(int i=1;i<s;i++){
		f[i]=(1+i*invs%Mod*f[i-1]%Mod)%Mod*s%Mod*(n-1)%Mod*qpow(s-i,Mod-2)%Mod;
	}
	for(int i=s-1;i>=0;i--){
		f[i]=(f[i]+f[i+1])%Mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+f[a[i]])%Mod;
	}
	cout<<(ans-f[0]*(n-1)%Mod+Mod)%Mod*qpow(n,Mod-2)%Mod<<endl;
	return 0;
}