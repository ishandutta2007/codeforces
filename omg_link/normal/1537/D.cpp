#include <stdio.h>

void solve(){
	int n;
	scanf("%d",&n);
	for(long long i=2;i<=n;i<<=2){
		if(i==n){
			puts("Bob");
			return;
		}
	}
	puts(n&1?"Bob":"Alice");
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}