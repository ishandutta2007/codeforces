#include <bits/stdc++.h>
using namespace std;
void get(int &x)
{
	char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	x=c-'0';
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
}
const int maxn=105;
int dp[maxn][maxn*maxn],mx[maxn][maxn],a[maxn][maxn],num[maxn],n,m;
int main()
{
	get(n);
	get(m);
	for(int i=1;i<=n;i++)
	{
		get(num[i]);
		for(int j=1;j<=num[i];j++)get(a[i][j]);
		int sl=0,sr=0;
		for(int l=0;l<=num[i];l++)
		{
			sl+=a[i][l];
			sr=0;
			for(int r=num[i]+1;r>=0&&r>l;r--)
			{
				sr+=a[i][r];
				mx[i][l+num[i]-r+1]=max(mx[i][l+num[i]-r+1],sl+sr);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=num[i]&&k<=j;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+mx[i][k]);
	printf("%d\n",dp[n][m]);
	return 0;
}