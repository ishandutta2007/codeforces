#include <stdio.h>
#define MN 100000

int n;
char a[MN+5],b[MN+5];

void solve(){
	scanf("%d%s",&n,&b[1]);
	a[1] = '1';
	for(int i=2;i<=n;i++){
		for(a[i]='1';a[i]+b[i]==a[i-1]+b[i-1];a[i]--);
	}
	a[n+1] = '\0';
	puts(a+1);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}