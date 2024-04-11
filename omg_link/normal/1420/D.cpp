#include <stdio.h>
#include <algorithm>
#include <queue>
#define MN 300000
typedef long long LL;
const int mod=998244353;

int n,k,ans=0;

struct lamp{
	int l,r;
}l[MN+5];

std::priority_queue<int,std::vector<int>,std::greater<int>> pq;

int fac[MN+5],inv[MN+5];

int qpow(LL bsc,int x){
	LL ret = 1;
	while(x){
		if(x&1) ret=(ret*bsc)%mod;
		bsc=(bsc*bsc)%mod;
		x>>=1;
	}
	return ret;
}

int C(int n,int m){
	LL tmp = (1ll*fac[n]*inv[m])%mod;
	return (tmp*inv[n-m])%mod;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i].l,&l[i].r);
		l[i].r++;
	}
	std::sort(l+1,l+1+n,[](lamp a,lamp b)->bool{
		return a.l<b.l;
	});
	fac[0] = 1;
	for(int i=1;i<=n;i++)
		fac[i] = (1ll*i*fac[i-1])%mod;
	inv[n] = qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)
		inv[i] = (1ll*inv[i+1]*(i+1))%mod;
	for(int i=1,num=0;i<=n;i++){
		while((!pq.empty())&&pq.top()<=l[i].l){
			pq.pop();
			num--;
		}
		if(num>=k-1){
			ans = (ans+C(num,k-1))%mod;
		}
		pq.push(l[i].r);
		num++;
	}
	printf("%d\n",ans);
}