#include <stdio.h>

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n&1){
		k--;
		int c = (n-1)/2;
		int ans = n-k/c*c+1+k%c;
		ans = (ans%n+n)%n;
		if(ans==0) ans = n;
		printf("%d\n",ans);
	}else{
		int ans = k%n;
		if(ans==0) ans = n;
		printf("%d\n",ans);
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}