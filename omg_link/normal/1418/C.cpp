#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,a[MN+5],f[MN+5][2];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0][0] = 0;
	f[0][1] = 0x3fffffff;
	f[1][0] = f[0][1];
	f[1][1] = f[0][0]+a[1];
	for(int i=2;i<=n;i++){
		f[i][0] = std::min(f[i-1][1],f[i-2][1]);
		f[i][1] = std::min(f[i-1][0]+a[i],f[i-2][0]+a[i]+a[i-1]);
	}
	printf("%d\n",std::min(f[n][0],f[n][1]));
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}