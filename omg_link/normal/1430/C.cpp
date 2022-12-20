#include <stdio.h>

int n;

void solve(){
	scanf("%d",&n);
	if(n==2){
		printf("2\n");
		printf("1 2\n");
	}else{
		printf("2\n");
		printf("%d %d\n",n,n-2);
		printf("%d %d\n",n-1,n-1);
		for(int i=n-1;i-2>=1;i--)
			printf("%d %d\n",i,i-2);
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}