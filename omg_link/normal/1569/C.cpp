#include <stdio.h>
#include <algorithm>
#include <functional>
#define MN 200000
typedef long long ll;
const int mod = 998244353;

using std::greater;
using std::sort;

int n,a[MN+5];

int fac[MN+5],inv[MN+5];

int qpow(int bsc,int y){
	int ret = 1;
	while(y){
		if(y&1) ret = (ll)ret*bsc%mod;
		bsc = (ll)bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}

void init(){
	fac[0] = 1;
	for(int i=1;i<=MN;i++)
		fac[i] = (ll)fac[i-1]*i%mod;
	inv[MN] = qpow(fac[MN],mod-2);
	for(int i=MN-1;i>=0;i--)
		inv[i] = (ll)inv[i+1]*(i+1)%mod;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,greater<int>());
	if(a[1]==a[2]){
		printf("%d\n",fac[n]);
		return;
	}
	int cnt = 0;
	for(int i=2;i<=n;i++)
		if(a[i]==a[1]-1) cnt++;
	int ans = (ll)fac[n]*(1-qpow(cnt+1,mod-2)+mod)%mod;
	printf("%d\n",ans);
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--) solve();
}