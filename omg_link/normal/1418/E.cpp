#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;
const int mod = 998244353;

int n,m;
int d[MN+5];
int pre[MN+5],suf[MN+5];

int qpow(LL bsc,int y){
	LL ret = 1;
	while(y){
		if(y&1) ret=(ret*bsc)%mod;
		bsc=(bsc*bsc)%mod;
		y>>=1;
	}
	return ret;
}

int inv(int x){
	return qpow(x,mod-2);
}

int bins(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(d[mid]<x) l = mid+1;
		else r = mid-1;
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	std::sort(d+1,d+1+n);
	for(int i=1;i<=n+1;i++) pre[i] = (pre[i-1] + d[i])%mod;
	for(int i=n;i>=0;i--) suf[i] = (suf[i+1] + d[i])%mod;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		int p = bins(b);
		int num = n-p;
		LL ans1 = (1ll*pre[p]*std::max(num+1-a,0))%mod;
		ans1 = (ans1*inv(num+1))%mod;
		LL ans2 = (1ll*suf[p+1]*std::max(num-a,0))%mod;
		ans2 = (ans2*inv(num))%mod;
		printf("%lld\n",(ans1+ans2)%mod);
	}
}