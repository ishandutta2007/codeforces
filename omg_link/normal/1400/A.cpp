#include <stdio.h>
#define MN 100

int n;
char s[MN+5];

void solve(){
	scanf("%d%s",&n,&s[1]);
	for(int i=0;i<n;i++)
		putchar(s[n]);
	putchar('\n');
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}