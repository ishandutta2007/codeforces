#include <stdio.h>
#include <algorithm>
#define MN 500

using std::min;

using ll = long long;

int a[MN+5][MN+5];

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	ll ans = 0;
	for(int i=n+1;i<=2*n;i++){
		for(int j=n+1;j<=2*n;j++){
			ans += a[i][j];
		}
	}
	ans += min({a[n+1][1],a[2*n][1],a[2*n][n],a[n+1][n],a[1][n+1],a[1][2*n],a[n][2*n],a[n][n+1]});
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}