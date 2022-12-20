#include <stdio.h>
#define MN 1000
int n,m;
char c[MN+5][MN+5];
bool checkp(int x,int y){
	if(x<=1||x>=n||y<=1||y>=m) return false;
	for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++){
			if(i==x&&j==y) continue;
			if(c[i][j]!='#') return false;
		}
	return true;
}
bool check(int x,int y){
	if(c[x][y]=='.') return true;
	for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++){
			if(i==x&&j==y) continue;
			if(checkp(i,j)) return true;
		}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&c[i][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!check(i,j)) return 0*puts("NO");
	puts("YES");
}