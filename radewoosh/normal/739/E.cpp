#include <bits/stdc++.h>
using namespace std;

int n, a, b;

pair <double,double> p[2007];
double mi[2007];

pair <double,int> dp[2007][2007];

double bsa, bsb, bss;

pair <double,int> por(pair <double,int> a, pair <double,int> b)
{
	a.second*=-1;
	b.second*=-1;
	if (a>b)
	{
		a.second*=-1;
		return a;
	}
	b.second*=-1;
	return b;
}

pair <double,int> check(double v)
{
	for (int i=0; i<=n; i++)
		for (int j=0; j<=a; j++)
			dp[i][j]={-10000.0, 0};
	dp[0][0]={0.0, 0};
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=a; j++)
		{
			//tak
				dp[i+1][j+1]=por(dp[i+1][j+1], {dp[i][j].first+mi[i+1]-v, dp[i][j].second+1});
				dp[i+1][j+1]=por(dp[i+1][j+1], {dp[i][j].first+p[i+1].first, dp[i][j].second});
			//nie
				dp[i+1][j]=por(dp[i+1][j], {dp[i][j].first+p[i+1].second-v, dp[i][j].second+1});
				dp[i+1][j]=por(dp[i+1][j], {dp[i][j].first, dp[i][j].second});
		}
	}
	return dp[n][a];
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i=1; i<=n; i++)
		scanf("%lf", &p[i].first);
	for (int i=1; i<=n; i++)
		scanf("%lf", &p[i].second);
	for (int i=1; i<=n; i++)
		mi[i]=p[i].first+p[i].second-p[i].first*p[i].second;
	bsa=0.0;
	bsb=1.0;
	for (int h=1; h<=30 && bsa<bsb; h++)
	{
		bss=(bsa+bsb)/2;
		pair <double,int> r1=check(bss);
		if (r1.second>b)
			bsa=bss;
		else
			bsb=bss;
	}
	printf("%6lf\n", check(bsa).first+b*bsa);
	return 0;
}