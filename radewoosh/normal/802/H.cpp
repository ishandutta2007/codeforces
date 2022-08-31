#include <bits/stdc++.h>
using namespace std;
 
long long k;
 
int n;
long long dp[5007][9];
int co[5007];
 
string slo="-RADEWOSH";
 
string wyn;
 
int main()
{
	scanf("%lld", &k);
	dp[0][0]=1;
	while(dp[n][7]*100<k)
	{
		n++;
		co[n]=(n-1)%7+1;
		for (int i=0; i<=7; i++)
			dp[n][i]=dp[n-1][i];
		dp[n][co[n]]+=dp[n-1][co[n]-1];
	}
	for (int i=n; i; i--)
	{
		while(k && dp[i][7]<=k)
		{
			k-=dp[i][7];
			wyn+='H';
		}
		wyn+=slo[co[i]];
	}
	reverse(wyn.begin(), wyn.end());
	cout << wyn << " RADEWOSH" << endl;
	return 0;
}