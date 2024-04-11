#include <stdio.h>

void solve(){
	int n,a,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		tot += a;
	}
	if(tot<n){
		puts("1");
	}else if(tot==n){
		puts("0");
	}else{
		printf("%d\n",tot-n);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}