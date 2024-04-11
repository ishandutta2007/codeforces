#include <stdio.h>

void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	if((x+y)&1){
		puts("-1 -1");
	}else{
		int d = (x+y)/2;
		if(d<=x){
			printf("%d %d\n",x-d,y);
		}else{
			printf("%d %d\n",x,y-d);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}