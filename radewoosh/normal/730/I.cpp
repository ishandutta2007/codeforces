#include <bits/stdc++.h>
using namespace std;

int n, p, s;

int a[10007];
int b[10007];

int dos[10007];

int dp[3007][3007];
int dod[3007][3007];

int wz[3007];

vector <int> jed, dru;

bool mniej(int aa, int bb)
{
	return a[aa]>a[bb];
}

int main()
{
	scanf("%d%d%d", &n, &p, &s);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for (int i=1; i<=n; i++)
		dos[i]=i;
	sort(dos+1, dos+1+n, mniej);
	for (int i=0; i<=n+1; i++)
	{
		for (int j=0; j<=n+1; j++)
		{
			dp[i][j]=-1000000000;
		}
	}
	dp[0][0]=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=s; j++)
		{
			int y=i-j;
			if (dp[i][j]+b[dos[i+1]]>dp[i+1][j+1])
			{
				dod[i+1][j+1]=1;
				dp[i+1][j+1]=dp[i][j]+b[dos[i+1]];
			}
			int faj=0;
			if (y<p)
				faj=a[dos[i+1]];
			if (dp[i][j]+faj>dp[i+1][j])
			{
				dod[i+1][j]=0;
				dp[i+1][j]=dp[i][j]+faj;
			}
		}
	}
	int v=s;
	for (int i=n; i; i--)
	{
		if (dod[i][v])
		{
			dru.push_back(dos[i]);
			wz[dos[i]]=1;
			v--;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if ((int)jed.size()<p && !wz[dos[i]])
		{
			jed.push_back(dos[i]);
		}
	}
	sort(jed.begin(), jed.end());
	sort(dru.begin(), dru.end());
	printf("%d\n", dp[n][s]);
	for (int i=0; i<p; i++)
		printf("%d ", jed[i]);
	printf("\n");
	for (int i=0; i<s; i++)
		printf("%d ", dru[i]);
	printf("\n");
	return 0;
}