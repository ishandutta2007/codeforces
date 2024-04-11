#include <stdio.h>
#include <algorithm>
#define MN 50

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans = 0;
	for(int i=2;i<=n;i++){
		int x = a[i-1];
		int y = a[i];
		if(x>y) std::swap(x,y);
		while(2*x<y){
			x *= 2;
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}