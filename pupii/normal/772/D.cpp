#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int S_tot[1000007],S_sum[1000007],S_cnt[1000007];
int pow2[1000010],inv[1000010];
int main(){
#ifndef ONLINE_JUDGE//hh
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),x;
	pow2[0]=pow2[1]=1;for(int i=2;i<=1000000;++i)pow2[i]=pow2[i-1]*2%mod;
	for(int i=1;i<=n;++i){
		x=gi();
		S_sum[x]=(S_sum[x]+x)%mod;
		++S_cnt[x];
	}
	inv[1]=1;for(int i=2;i<=1000000;++i)inv[i]=mod-1ll*inv[mod%i]*(mod/i)%mod;
	for(int i=0;i<1000000;++i){
		for(int j=1,C=1;j<=S_cnt[i];++j){
			C=1ll*C*(S_cnt[i]-j+1)%mod*inv[j]%mod;
			S_tot[i]=(S_tot[i]+1ll*C*i%mod*i%mod*j%mod*j%mod)%mod;
		}
	}
	for(int i=1;i<=100000;i*=10)
		for(int j=999999;~j;--j)
			if(j/i%10){
				int at=S_tot[j],as=S_sum[j],ac=S_cnt[j];
				int bt=S_tot[j-i],bs=S_sum[j-i],bc=S_cnt[j-i];
				S_cnt[j-i]+=ac;
				S_sum[j-i]=(as+bs)%mod;
				S_tot[j-i]=(1ll*at*pow2[bc+1]%mod+1ll*bt*pow2[ac+1]%mod+1ll*2*as%mod*pow2[ac]%mod*bs%mod*pow2[bc]%mod)%mod;
			}
	for(int i=1;i<=100000;i*=10)
		for(int j=0;j<1000000;++j)
			if(j/i%10!=9)S_tot[j]=(S_tot[j]-S_tot[j+i]+mod)%mod;
	ll ans=0;
	for(int i=0;i<1000000;++i)ans^=1ll*i*S_tot[i];
	printf("%lld\n",ans);
	return 0;
}