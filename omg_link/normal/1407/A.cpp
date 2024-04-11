#include <stdio.h>
#include <stdlib.h>
#define MN 1000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	int c[2]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	if((n>>1)&1){
		if(c[0]>=c[1]){
			printf("%d\n",(n>>1));
			for(int i=1;i<=(n>>1);i++)
				printf("%d ",0);
		}else{
			printf("%d\n",(n>>1)+1);
			for(int i=1;i<=(n>>1)+1;i++)
				printf("%d ",1);
		}
	}else{
		printf("%d\n",n>>1);
		if(c[0]>=c[1]){
			for(int i=1;i<=(n>>1);i++)
				printf("%d ",0);
		}else{
			for(int i=1;i<=(n>>1);i++)
				printf("%d ",1);
		}
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}