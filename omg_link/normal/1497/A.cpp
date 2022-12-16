#include <stdio.h>
#include <string.h>
#define MN 100

int cnt[MN+5];

void solve(){
	memset(cnt,0,sizeof(cnt));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=0;i<=MN;i++){
		if(cnt[i]){
			printf("%d ",i);
			cnt[i]--;
		}
	}
	for(int i=0;i<=MN;i++){
		while(cnt[i]){
			printf("%d ",i);
			cnt[i]--;
		}
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}