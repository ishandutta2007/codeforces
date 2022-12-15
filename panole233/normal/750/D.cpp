#include<cstdio>
#include<cstring>

int T,n,x,y,ans;
bool a[351][351][8],b[351][351][8],m[351][351];
int dd[8][2]={{4,5},{6,7},{4,6},{5,7},{0,2},{0,3},{1,2},{1,3}};
int d[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

int main()
{
	scanf("%d",&T);
	a[170][170][0]=1;
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=350; i++)
			for (int j=1; j<=350; j++)
				for (int k=0; k<=7; k++)
					if(a[i][j][k])
					{
						x=i; y=j;
						for (int s=1; s<=n; s++) x+=d[k][0],y+=d[k][1],m[x][y]=1;
						b[x][y][dd[k][0]]=b[x][y][dd[k][1]]=1;
					}
		for (int i=1; i<=350; i++)
			for (int j=1; j<=350; j++)
				for (int k=0; k<=7; k++)
					a[i][j][k]=b[i][j][k];
		memset(b,0,sizeof b);
	}
	ans=0;
	for (int i=1; i<=350; i++)
		for (int j=1; j<=350; j++) 
			if (m[i][j]) ans++;
	printf("%d\n",ans);
	return 0;
}