#include <stdio.h>
#define MN 200000

char ans[MN+5];

void solve(){
	int n;
	scanf("%d",&n);
	ans[1] = '9';
	ans[2] = '8';
	char c = '9';
	for(int i=3;i<=n;i++){
		ans[i] = c;
		c++;
		if(c>'9') c -= 10;
	}
	ans[n+1] = '\0';
	puts(&ans[1]);
} 

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}