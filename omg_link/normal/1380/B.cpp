#include <stdio.h>
#include <string.h>
#define MN 200000

char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	int len = strlen(&s[1]);
	int R=0,S=0,P=0;
	for(int i=1;i<=len;i++){
		if(s[i] == 'R') R++;
		if(s[i] == 'S') S++;
		if(s[i] == 'P') P++;
	}
	if(R>=S && R>=P){
		for(int i=1;i<=len;i++)
			putchar('P');
		putchar('\n');
		return;
	}
	if(S>=R && S>=P){
		for(int i=1;i<=len;i++)
			putchar('R');
		putchar('\n');
		return;
	}
	if(P>=R && P>=S){
		for(int i=1;i<=len;i++)
			putchar('S');
		putchar('\n');
		return;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}