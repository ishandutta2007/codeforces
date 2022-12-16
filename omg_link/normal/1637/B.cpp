#include <stdio.h>
#define MN 100

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans += 2*i*(n-i+1);
		}else{
			ans += i*(n-i+1);
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}