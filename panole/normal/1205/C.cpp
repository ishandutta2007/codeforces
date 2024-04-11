#include<bits/stdc++.h>
using namespace std;

int col[101][101],n;

int query(int xl,int yl,int xr,int yr)
{
	printf("? %d %d %d %d\n",xl,yl,xr,yr);
	fflush(stdout); int ans;
	scanf("%d",&ans); return ans^1;
}

int main()
{
	scanf("%d",&n);
	col[1][1]=1,col[n][n]=0;
	for (int i=4; i<2*n; i+=2)
	{
		if (i<=n+1) col[1][i-1]=query(1,i-3,1,i-1)^col[1][i-3],col[i-1][1]=query(i-3,1,i-1,1)^col[i-3][1];
		for (int j=2; j<=n&&j<i-1; j++)
			if (i-j<=n) col[i-j][j]=query(i-j-1,j-1,i-j,j)^col[i-j-1][j-1];
	}
	col[1][2]=1,col[2][3]=query(1,2,2,3)^1,col[2][1]=query(2,1,2,3)^col[2][3];
	col[3][2]=query(2,1,3,2)^col[2][1];
	if (n>=5) col[4][1]=query(2,1,4,1)^col[2][1],col[1][4]=query(1,2,1,4)^col[1][2];
	for (int i=7; i<2*n; i+=2)
	{
		if (i<=n+1) col[1][i-1]=query(1,i-3,1,i-1)^col[1][i-3],col[i-1][1]=query(i-3,1,i-1,1)^col[i-3][1];
		for (int j=2; j<=n&&j<i-1; j++)
			if (i-j<=n) col[i-j][j]=query(i-j-1,j-1,i-j,j)^col[i-j-1][j-1];
	}
	int bo=0;
	for (int i=1; i<=n-2; i+=2)
	{
		if (!(col[i][i]^col[i+1][i]^col[i+1][i+1]^col[i+2][i+1]))
		{
			if (query(i,i,i+2,i+1)^col[i][i]^col[i+2][i+1]) bo=1;
			break;
		}
		if (!(col[i+1][i]^col[i+1][i+1]^col[i+2][i+1]^col[i+2][i+2]))
		{
			if (query(i+1,i,i+2,i+2)^col[i+1][i]^col[i+2][i+2]) bo=1;
			break;
		}
	}
	puts("!");
	for (int i=1; i<=n; i++,puts(""))
		for (int j=1 ;j<=n; j++) printf("%d",(((i+j)&1)?bo:0)^col[i][j]);
	fflush(stdout);
	return 0;
}