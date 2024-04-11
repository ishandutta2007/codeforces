#include <stdio.h>
#include <string.h>
#define MN 500000
typedef long long LL;
const int mod=1000000007;

int n;
LL x[MN+5];
int cnt[60][2];

void solve(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		for(int j=0;j<60;j++)
			cnt[j][bool(x[i]&(1ll<<j))]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int s1=0,s2=0;
		for(int j=0;j<60;j++){
			int b = (1ll<<j)%mod;
			if(x[i]&(1ll<<j)){
				s1 = (s1+1ll*b*n)%mod;
				s2 = (s2+1ll*b*cnt[j][1])%mod;
			}else{
				s1 = (s1+1ll*b*cnt[j][1])%mod;
			}
		}
		ans = (ans+1ll*s1*s2)%mod;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}