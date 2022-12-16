#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long ll;

using std::max;

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll ans = 0;
	for(int i=2;i<=n;i++)
		ans = max(ans,(ll)a[i-1]*a[i]);
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}