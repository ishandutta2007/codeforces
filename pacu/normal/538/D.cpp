#include <cstdio>
using namespace std;

int xp[2500];
int yp[2500];

char A[55][55];
char B[55][55];
bool pos[100][100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<(2*N);i++)
		for(int j=1;j<(2*N);j++)
			pos[i][j] = 1;
	for(int i=0;i<N;i++)
		scanf("%s",A[i]);
	int M = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(A[i][j]=='o')
			{
				xp[M] = i;
				yp[M++] = j;
			}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(A[i][j]=='.')
			{
				for(int k=0;k<M;k++)
					pos[(i-xp[k])+N][(j-yp[k])+N] = 0;
			}
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			B[i][j] = '.';
	for(int i=1;i<(2*N);i++)
		for(int j=1;j<(2*N);j++)
			for(int k=0;k<M;k++)
				if(pos[i][j])
					if(((xp[k]+i-N)>=0)&&((xp[k]+i-N)<N))
						if(((yp[k]+j-N)>=0)&&((yp[k]+j-N)<N))
							B[xp[k]+i-N][yp[k]+j-N] = 'x';
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if((A[i][j]=='x')&&(B[i][j]!='x'))
			{
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	for(int i=1;i<2*N;i++)
	{
		for(int j=1;j<2*N;j++)
		{
			if((i==N)&&(j==N))
				printf("o");
			else if(pos[i][j])
				printf("x");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}