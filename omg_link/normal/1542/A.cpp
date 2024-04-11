#include <stdio.h>

void solve(){
	int n,cnt[2]={0};
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		int a;
		scanf("%d",&a);
		cnt[a&1]++;
	}
	puts(cnt[0]==cnt[1]?"Yes":"No");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}