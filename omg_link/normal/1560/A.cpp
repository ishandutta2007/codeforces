#include <stdio.h>

void solve(){
	int k,ans;
	scanf("%d",&k);
	for(ans=1;k;ans++){
		if(ans%3==0||ans%10==3) continue;
		k--;
	}
	printf("%d\n",ans-1);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}