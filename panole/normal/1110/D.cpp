#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;
int f[2][9][9],t[1000001],x,n,m,mo[10],X,Y;

int main()
{
	scanf("%d%d",&n,&m); memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++) scanf("%d",&x),t[x]++;
	for (int i=0; i<=1; i++)
		for (int j=0; j<9; j++)
			for (int k=0; k<9; k++) f[i][j][k]=-inf;
	f[0][0][0]=0;
	for (int i=0; i<9; i++) mo[i]=i%3;
	for (int i=0; i<m; i++)
	{
		X=(i&1),Y=(X^1);
		int nw=t[i+1];
		if (nw>=6) nw=6+nw%3;
		for (int j=0; j<9; j++)
			for (int k=0; k<9; k++)
			{
				f[Y][k][nw]=max(f[Y][k][nw],f[X][j][k]);
				if (i>1)
				{
					for (int l=1; l<3; l++)
					{
						if (j<l||nw<l||k<l) continue;
						x=0; if (mo[j]<l) x--; if (mo[k]<l) x--; if (mo[nw]<l) x--;
						f[Y][k-l][nw-l]=max(f[Y][k-l][nw-l],f[X][j][k]+l+x);
					}
				}
				f[X][j][k]=-inf;
			}
	}
	int ans=0;
	for (int j=0; j<9; j++)
		for (int k=0; k<9; k++) ans=max(f[Y][j][k],ans);
	for (int i=1; i<=m; i++) ans+=t[i]/3;
	printf("%d\n",ans);
	return 0;
}