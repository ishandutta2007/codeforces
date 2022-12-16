#include <stdio.h>

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	while(k>3){
		n--,k--;
		printf("%d ",1);
	}
	if(n&1){
		printf("%d %d %d\n",1,n>>1,n>>1);
	}else{
		if((n>>1)&1){
			n -= 2;
			printf("%d %d %d\n",2,n>>1,n>>1);
		}else{
			printf("%d %d %d\n",n>>2,n>>2,n>>1);
		}
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}