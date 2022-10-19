#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

LL n,m,mod,inv[N],ans,cnt[N],pre[N];

void upd(LL &x,LL y){
	x=(x+y)%mod;
}

void solve(LL x,LL m){
	if (!m||x==1){
		++cnt[x];
		return;
	}
	solve((x+1)/2,m-1);
	solve(x/2,m-1);
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	m=min(m-1,20LL);
	solve(n,m);
	LL p=max(n,4LL);
	inv[1]=1; for (LL i=2;i<=p;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (LL i=1;i<=p;++i) pre[i]=(pre[i-1]+inv[i])%mod;
	for (LL i:{n>>m,(n>>m)+1}){
		upd(ans,cnt[i]*i%mod*(i-1)%mod*inv[4]);
		for (LL j:{n>>m,(n>>m)+1}){
			LL sum=0;
			for (LL k=1;k<=i;++k){
				upd(sum,(k-1)*(pre[k+j]-pre[k]));
			}
			sum=sum*inv[2]%mod;
			upd(ans,sum*cnt[i]%mod*(i==j?cnt[i]-1:cnt[j]));
		}
	}
	upd(ans,mod);
	printf("%lld\n",ans);
	
	return 0;
}