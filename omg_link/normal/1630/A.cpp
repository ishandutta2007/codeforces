#include <stdio.h>

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==n-1){
		if(n==4){
			puts("-1");
		}else{
			printf("%d %d\n",n-1,n-2);
			printf("%d %d\n",1,3);
			printf("%d %d\n",n-3,2);
			printf("%d %d\n",n-4,0);
			for(int i=4,mask=n-1;i<(n>>1);i++){
				printf("%d %d\n",i,mask^i);
			}
		}
	}else{
		for(int i=1,mask=n-1;i<(n>>1);i++){
			if(i==k||i==(mask^k)){
				if(i==k){
					printf("%d %d\n",0,mask^k);
				}else{
					printf("%d %d\n",0,i);
				}
			}else{
				printf("%d %d\n",i,mask^i);
			}
		}
		printf("%d %d\n",n-1,k);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}