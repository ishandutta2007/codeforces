#include <bits/stdc++.h>
using namespace std;
 
int n, k;
 
long double pra[2][707];
long double dp[2][707];
 
long double wyn;
 
long double gra;

long double tak, nie;
 
int x;
 
long double a, b, s;
 
double wyp;

int m=700;
 
void zer(int v)
{
	for (int i=0; i<=m; i++)
	{
		dp[v][i]=0.0;
		pra[v][i]=0.0;
	}
}
 
int main()
{
	gra=1;
	gra/=1000.0;
	gra/=1000.0;
	gra/=1000.0;
	gra/=1000.0;
	gra/=1000.0;
	scanf("%d%d", &n, &k);
	tak=1.0/k;
	nie=1.0-tak;
	pra[0][0]=1.0;
	for (int h=0; h<n; h++)
	{
		int i=h&1;
		zer(i^1);
 
		for (int j=0; j<=m; j++)
		{
			if (pra[i][j]<=gra)
			continue;
			if (k>1)
			{
				a=pra[i][j]*nie;
				b=pra[i^1][j];
				
				dp[i^1][j]=(dp[i][j]*a+dp[i^1][j]*b)/(a+b);
				pra[i^1][j]=a+b;
			}
				
			a=pra[i][j]*tak*((j+1.0)/(j+2.0));
			b=pra[i^1][j];
			
			dp[i^1][j]=((dp[i][j]+((j+2.0)/2.0))*a+dp[i^1][j]*b)/(a+b);
			pra[i^1][j]=a+b;
			
			a=pra[i][j]*tak*(1.0/(j+2.0));
			b=pra[i^1][j+1];
			
			dp[i^1][j+1]=(((dp[i][j]+(j+1.0)))*a+dp[i^1][j+1]*b)/(a+b);
			pra[i^1][j+1]=a+b;
		}
	}
	for (int i=0; i<=m; i++)
	{
		wyn+=dp[n&1][i]*pra[n&1][i]*k;
	}
	wyp=wyn;
	printf("%.11lf\n", wyp);
	return 0;
}