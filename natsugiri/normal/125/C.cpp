#include<cstdio>
int main(){
	int i,j,x,n,k;
	scanf("%d",&n);
	for(x=2;x*(x+1)<=n*2;x++);
	x--;
	printf("%d\n",x+1);
	int d[x+1][x];
	for(i=0;i<x;i++)printf("%s%d",i?" ":"",d[0][i]=i+1);
	puts("");
	for(j=1,k=x;j<=x;j++){
		for(i=0;i<j;i++)printf("%s%d",i?" ":"",d[j][i]=d[i][j-1]);
		for(;i<x;i++)printf("%s%d",i?" ":"",d[j][i]=++k);
		puts("");
	}
}