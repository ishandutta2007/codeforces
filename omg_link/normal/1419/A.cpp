#include <stdio.h>
#define MN 1000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	if(n&1){
		for(int i=1;i<=n;i+=2){
			if(a[i]&1){
				puts("1");
				return;
			} 
		}
		puts("2");
		return;
	}else{
		for(int i=2;i<=n;i+=2){
			if((a[i]&1)==0){
				puts("2");
				return;
			}
		}
		puts("1");
		return;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}