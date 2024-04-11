#include <stdio.h>

int n;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",(n+1)>>1);
	}
}