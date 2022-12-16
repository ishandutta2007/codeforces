#include <stdio.h>
#include <assert.h>

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ans = 0;
	for(int i=29,t=0;i>=0;i--){
		if(n&(1<<i)){
			if(m-(t|(1<<i))+1<(1<<i)){
				t |= 1<<i;
			}else{
				assert(false);
			}
		}else{
			if(m-t+1<(1<<i)){
				
			}else{
				t |= 1<<i;
				ans |= 1<<i;
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}