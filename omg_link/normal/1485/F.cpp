#include <stdio.h>
#include <unordered_map>
#define MN 200000
typedef long long LL;
const int mod = 1000000007;

int n,a[MN+5],f[MN+5];
LL pre[MN+5];
std::unordered_map<LL,int> mp;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i] = pre[i-1] + a[i];
	}
	mp.clear();
	int tot = 1;
	int ans = 1;
	mp[0] = 1;
	for(int i=1;i<=n;i++){
		f[i] = (tot+mod-mp[pre[i-1]])%mod;
		mp[pre[i-1]] = (mp[pre[i-1]]+f[i])%mod;
		ans = (ans+f[i])%mod;
		tot = (tot+f[i])%mod;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}