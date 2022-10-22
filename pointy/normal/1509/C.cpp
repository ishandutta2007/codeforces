#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=2005;
int n,m,T; 
ll a[N],b[N],dp[N][N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	n--;
	for (int i=1;i<=n;i++) dp[i][i]=b[i]*n;
	for (int len=2;len<=n;len++)
	{
		for (int i=1;i<=n;i++)
		{
			int j=i+len-1;
			if (j>n) break;
			dp[i][j]=min(dp[i][j-1]+b[j]*(n-len+1),dp[i+1][j]+b[i]*(n-len+1));
		}
	}
	cout << dp[1][n];
	return;
}

int main()
{
	T=1;
	while (T--)
	{
		work();
	}
	return 0;
}