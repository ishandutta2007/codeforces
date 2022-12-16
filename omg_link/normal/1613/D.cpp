#include <stdio.h>
#define MN 500000

const int mod = 998244353;

using ll = long long;

int n,a[MN+5];
ll f[MN+5][2];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++){
		f[i][0] = f[i][1] = 0;
	}
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		//new mex = a[i]-1
		if(a[i]-1>=0){
			f[a[i]-1][1] = (f[a[i]-1][1]+f[a[i]-1][0]+f[a[i]-1][1])%mod;
		}
		//new mex = a[i]+1 && no a[i]+2
		if(a[i]+1<=n){
			f[a[i]+1][0] = (f[a[i]+1][0]+f[a[i]][0]+f[a[i]+1][0])%mod;
		}
		//new mex = a[i]+1 && yes a[i]+2
		if(a[i]+1<=n){
			f[a[i]+1][1] = (f[a[i]+1][1]+f[a[i]+1][1])%mod;
		}
	}
	ll ans = -1;
	for(int i=0;i<=n;i++){	
		ans += f[i][0]+f[i][1];
	}
	ans = (ans%mod+mod)%mod;
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}