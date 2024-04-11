#include <stdio.h>
#define MN 1005000

bool f[MN+5];

void init(int n){
	f[0] = true;
	for(int i=0;i<=n;i++){
		if(f[i]){
			f[i+2020] = true;
			f[i+2021] = true;
		}
	}
}

void solve(){
	int n;
	scanf("%d",&n);
	puts(f[n]?"YES":"NO");
}

int main(){
	init(1e6);
	int T; scanf("%d",&T);
	while(T--) solve();
}