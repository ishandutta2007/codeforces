#include <stdio.h>
#include <stdlib.h>
#define MN 500
int n,m,a[MN+5][MN+5],b[MN+5][MN+5];
void flip(int x,int y){
	a[x][y]^=1;
	a[x][m]^=1;
	a[n][y]^=1;
	a[n][m]^=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&b[i][j]);
			a[i][j]^=b[i][j];
		}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m-1;j++)
			if(a[i][j]) flip(i,j);
		if(a[i][m]){
			puts("No");
			exit(0);
		}
	}
	for(int j=1;j<=m;j++)
		if(a[n][j]){
			puts("No");
			exit(0);
		}
	puts("Yes");
}