#include <stdio.h>

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((j-i)&1){
				if((n&1)==0&&j-i==1&&(i&1))
					printf("0 ");
				else
					printf("1 ");
			}else{
				printf("-1 ");
			}
		}
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}