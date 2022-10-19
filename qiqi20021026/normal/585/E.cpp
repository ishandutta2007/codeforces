#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 600000
#define M 10500000

const LL mod=1000000007;
int n,m,tot,a[N],pw[N],pr[M],cnt[M],mu[M],vis[M];
LL ans;

void getprime(){
	mu[1]=1;
	for (int i=2;i<=m;++i){
		if (!vis[i]){
			pr[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=tot&&pr[j]*i<=m;++j){
			vis[pr[j]*i]=pr[j];
			if (i%pr[j]==0){
				mu[pr[j]*i]=0;
				break;
			}
			mu[pr[j]*i]=-mu[i];
		}
	}
	for (int i=1;i<=tot;++i)
		for (int j=m/pr[i];j;--j) cnt[j]+=cnt[j*pr[i]];
}

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){scanf("%d",a+i); ++cnt[a[i]];}
	pw[0]=1; for (int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
	m=10000000;
	getprime();
	for (int i=1;i<=m;++i){
		upd(ans,(LL)-n*mu[i]*(pw[cnt[i]]-1));
		if (cnt[i]) upd(ans,(LL)2*mu[i]*pw[cnt[i]-1]%mod*cnt[i]);
	}
	printf("%lld\n",(ans+mod)%mod);
	
	return 0;
}