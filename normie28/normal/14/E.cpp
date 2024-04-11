#include<cstdio>
#define For(i,_,__) for(int i=_;i<=__;i++)
int n,t,ans,f[21][5][5][11][11];
int main()
{
	scanf("%d%d",&n,&t);
	For(i,1,4)For(j,1,4)f[2][i][j][0][0]=i!=j;
	For(i,3,n)For(j,1,4)For(k,1,4)
	For(x,0,t)For(y,0,t)For(l,1,4)if(k!=l)
		f[i][k][l][x+(j<k&&k>l)][y+(j>k&&k<l)]+=f[i-1][j][k][x][y];
	For(i,1,4)For(j,1,4)ans+=f[n][i][j][t][t-1];
	printf("%d\n",ans);
}