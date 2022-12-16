#include <stdio.h>
#define MN 50

char s[MN+5][MN+5];

int n,m,r,c;

bool noBlack(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='B') return false;
	return true;
}

bool isFilledRow(int r){
	for(int j=1;j<=m;j++)
		if(s[r][j]!='B') return false;
	return true;
}

bool isFilledCol(int c){
	for(int i=1;i<=n;i++)
		if(s[i][c]!='B') return false;
	return true;
}

bool hasFilledRow(int r){
	for(int j=1;j<=m;j++)
		if(s[r][j]=='B') return true;
	return false;
}

bool hasFilledCol(int c){
	for(int i=1;i<=n;i++)
		if(s[i][c]=='B') return true;
	return false;
}

void solve(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	if(noBlack()){
		puts("-1");
		return;
	}
	if(s[r][c]=='B'){
		puts("0");
		return;
	}
	if(hasFilledRow(r)||hasFilledCol(c)){
		puts("1");
		return;
	}
	puts("2");
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}