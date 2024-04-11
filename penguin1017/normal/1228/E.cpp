#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
using namespace std;
const int N=(int)1e5+9; 
const ll mod=(ll)1e9+7;
ll jie[N],inv[N],f[N];
void pre(){
	jie[0]=1;inv[0]=inv[1]=1;
	rep(i,1,N)jie[i]=jie[i-1]*i%mod;
	rep(i,2,N){
		int k=mod/i,r=mod%i;
		inv[i]=-k*inv[r]%mod;
		if(inv[i]<0)inv[i]+=mod;
	}
	rep(i,1,N)inv[i]=inv[i-1]*inv[i]%mod;
}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	pre();
	ll n,k;
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		f[i]=jie[n]*inv[i]%mod*inv[n-i]%mod*quick(k-1,i*n)%mod;
		ll temp=quick(quick(k,n-i)-quick(k-1,n-i),n);
		if(temp<0)temp+=mod;
		f[i]=f[i]*temp%mod; 
	}
	ll ans=0;
	rep(i,0,n+1){
		if(i&1)ans-=f[i];
		else ans+=f[i];
	}
	ans%=mod;
	if(ans<0)ans+=mod;
	printf("%lld",ans);
}