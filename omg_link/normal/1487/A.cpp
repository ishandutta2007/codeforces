#include <stdio.h>
#include <algorithm>
#define MN 100

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	int min = 101;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		min = std::min(min,a[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i]!=min)
			ans++;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}