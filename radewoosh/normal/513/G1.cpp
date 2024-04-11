#include <bits/stdc++.h>
using namespace std;

const int nax=207;

int n, k;

int tab[nax];

double dp[nax][nax][nax];

double dziel;

double wyn;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			dp[0][i][j]=(tab[i]>tab[j])*1.0;
	dziel=n*(n+1)/2.0;
	for (int h=1; h<=k; h++)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				for (int ii=1; ii<=n; ii++)
				{
					for (int jj=ii; jj<=n; jj++)
					{
						int ni=i, nj=j;
						if (i>=ii && i<=jj)
							ni=jj+ii-i;
						if (j>=ii && j<=jj)
							nj=jj+ii-j;
						if (ni>nj)
							dp[h][nj][ni]+=(1.0-dp[h-1][i][j])/dziel;
						else
							dp[h][ni][nj]+=dp[h-1][i][j]/dziel;
					}
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			wyn+=dp[k][i][j];
	printf("%.11lf\n", wyn);
	return 0;
}