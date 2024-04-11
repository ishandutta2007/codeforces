#include <stdio.h>
#define MN 50000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		if(a[i-1]<=a[i]){
			puts("YES");
			return;
		}
	puts("NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}