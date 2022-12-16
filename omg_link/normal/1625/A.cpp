#include <stdio.h>
#define MN 100

void solve(){
	int n,l;
	scanf("%d%d",&n,&l);
	int cnt[30] = {0};
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;j<l;j++){
			if(a&(1<<j)){
				cnt[j]++;
			}else{
				cnt[j]--;
			}
		}
	}
	int ans = 0;
	for(int j=0;j<l;j++){
		if(cnt[j]>=0){
			ans |= 1<<j;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}