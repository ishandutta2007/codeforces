#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 800000

const LL mod=1000000007;
LL n,m,x,ans,pre1[N],pre2[N],pre[N],suf[N],fac[N],ifac[N],cnt[32];
vector<LL> v[N];

inline void upd(LL &x,LL y){x=((x+y)%mod+mod)%mod;}

LL inv(LL x){
	return x==1?1:(mod-mod/x)*inv(mod%x)%mod;
}

LL c(LL x,LL y){
	return x<y?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld",&x);
		for (LL j=2;j*j<=x;j+=j==2?1:2){
			LL t=0;
			for (;x%j==0;x/=j) ++t;
			v[j].push_back(t);
		}
		if (x>1) v[x].push_back(1);
	}
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	pre1[0]=c(n-1,0); for (LL i=1;i<=n;++i) pre1[i]=(pre1[i-1]+c(n-1,i))%mod;
	pre2[0]=pre1[0]; for (LL i=1;i<=n;++i) pre2[i]=(pre2[i-1]+pre1[i])%mod;
	m=300000;
	for (LL i=2;i<=m;++i){
		memset(cnt,0,sizeof cnt);
		for (LL j=0;j<(LL)v[i].size();++j) ++cnt[v[i][j]];
		cnt[0]+=n-v[i].size();
		pre[0]=cnt[0]; for (LL j=1;j<=30;++j) pre[j]=pre[j-1]+cnt[j];
		suf[30]=cnt[30]; for (LL j=29;~j;--j) suf[j]=suf[j+1]+cnt[j];
		for (LL j=0;j<=30;++j){
			upd(ans,j*((pre[j]?pre2[pre[j]-1]:0)-(j&&pre[j-1]?pre2[pre[j-1]-1]:0)));
			upd(ans,-j*((suf[j]?pre2[suf[j]-1]:0)-(j<30&&suf[j+1]?pre2[suf[j+1]-1]:0)));
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}