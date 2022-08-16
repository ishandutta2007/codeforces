# include <cstdio>

using namespace std;

int ar[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int neigh[][2]={{0,-1},{0,1},{0,0},{-1,0},{1,0},{-1,1},{-1,-1},{1,1},{1,-1}};

int main()
{
	int n;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			scanf("%d",&n);
			if(n%2==0)continue;
			for(int m=0;m<5;m++)
			{
				int ii=i+neigh[m][0],jj=j+neigh[m][1];
				if(ii>=0&&ii<=2&&jj>=0&&jj<=2)ar[ii][jj]=1-ar[ii][jj];
			}
		}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			printf("%d",1-ar[i][j]);
		printf("\n");
	}
	return 0;

}