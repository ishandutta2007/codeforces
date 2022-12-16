#include <stdio.h>
#define MN 100000

int x,y;
char s[MN+5];

void solve(){
	scanf("%d%d%s",&x,&y,&s[0]);
	int maxX=0,minX=0,maxY=0,minY=0;
	for(int i=0;s[i];i++){
		if(s[i]=='U') maxY++;
		if(s[i]=='D') minY--;
		if(s[i]=='L') minX--;
		if(s[i]=='R') maxX++;
	}
	puts(minX<=x&&x<=maxX&&minY<=y&&y<=maxY?"YES":"NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}