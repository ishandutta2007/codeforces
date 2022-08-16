# include <cstdio>

char win[300][300][300];
char p1[]="BitLGM",p2[]="BitAryo";

int main()
{
	int N;
	scanf("%d",&N);

	if(N==1)
	{
		int a;
		scanf("%d",&a);
		if(a==0)printf("%s\n",p2);
		else printf("%s\n",p1);
	}
	else if(N==2)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
			{
				if(win[0][i][j])continue;
				for(int k=i+1;k<=a;k++)win[0][k][j]=1;
				for(int k=j+1;k<=b;k++)win[0][i][k]=1;
				for(int k=i+1,l=j+1;k<=a&&l<=b;k++,l++)
					win[0][k][l]=1;
			}
		if(win[0][a][b]==0)printf("%s\n",p2);
		else printf("%s\n",p1);
	}
	else if(N==3)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
				for(int k=0;k<=c;k++)
				{
					if(win[i][j][k])continue;
					for(int l=i+1;l<=a;l++)win[l][j][k]=1;
					for(int l=j+1;l<=b;l++)win[i][l][k]=1;
					for(int l=k+1;l<=c;l++)win[i][j][l]=1;
					for(int l=i+1,m=j+1,n=k+1;l<=a&&m<=b&&n<=c;l++,m++,n++)
						win[l][m][n]=1;
				}
		if(win[a][b][c]==0)printf("%s\n",p2);
		else printf("%s\n",p1);
	}
	return 0;
}