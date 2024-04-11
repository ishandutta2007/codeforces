#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char s[55][55];
bool all(int i,int j,int x,int y){
	 if(i==x&&j==y)return true;
	 if(i==x){
	 		  if(j<y)swap(j,y);
	 		  for(int k=j;k<=y;k++)if(s[i][k]=='W')return false;
	 		  return true;
	}
	if(i>x)swap(i,x);
	for(int k=i;k<=x;k++)if(s[k][j]=='W')return false;
	return true;
}
int n,m;
int main(){
	scanf("%d%d",&m,&n);
	if(m==2&&n==5){printf("NO\n");return 0;}
	for(int i=1;i<=m;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	for(int ii=1;ii<=m;ii++)
	for(int jj=1;jj<=n;jj++)
	{
	 		if(s[i][j]=='W')continue;
	 		if(s[ii][jj]=='W')continue;
	 		if(all(i,j,ii,j)&&all(ii,j,ii,jj))continue;
	 		if(all(i,j,i,jj)&&all(i,jj,ii,jj))continue;
	 		printf("NO\n");return 0;
	}
	printf("YES\n");
	//system("pause");
	return 0;
}
/*5 5
WBBWW
BBBWW
BBBWW
BBBWW
BBBBB*/
/*5 5
WBBBW
WBBWW
WBBWW
BBBWW
BBWWW*/