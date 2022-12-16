#include <stdio.h>
#define MN 50

int n;
char s[MN+5];

void solve(){
	scanf("%d%s",&n,&s[1]);
	for(int i=1;i<n;i++)
		if(s[i]!=s[i+1]){
			printf("%d %d\n",i,i+1);
			return;
		}
	puts("-1 -1");
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}