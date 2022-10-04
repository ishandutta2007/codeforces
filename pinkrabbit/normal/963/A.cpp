#include<cstdio>
#define ll long long
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}

const ll Mod=1000000009;
ll n,a,b,k;
ll tmp,Sum;
char str[100005];

int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k); tmp=Pow(a,n,Mod); a=Pow(a,Mod-2ll,Mod);
	ll ab=a*b%Mod;
	scanf("%s",str);
	for(ll i=0;i<k;++i){
		ll s=(str[i]=='+'?1ll:Mod-1ll);
		s=s*Pow(ab,i,Mod)%Mod;
		if(Pow(ab,k,Mod)!=1) s=s*((Pow(ab,n+1ll,Mod)+Mod-1ll)%Mod)%Mod*(Pow((Pow(ab,k,Mod)+Mod-1ll)%Mod,Mod-2ll,Mod))%Mod;
		else s=s*((n+1)/k)%Mod;
		Sum=(Sum+s)%Mod;
	} printf("%lld",tmp*Sum%Mod);
	return 0;
}