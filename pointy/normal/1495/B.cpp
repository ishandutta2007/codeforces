#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,m,T; 
int a[N],dp[2][N];
int ans[N];
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
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	dp[0][1]=0;
	for (int i=2;i<=n;i++)
	{
		if (a[i]>a[i-1]) dp[0][i]=dp[0][i-1]+1;
		else dp[0][i]=0;
	}
	dp[1][1]=0;
	for (int i=n-1;i>=1;i--)
	{
		if (a[i]>a[i+1]) dp[1][i]=dp[1][i+1]+1;
		else dp[1][i]=0;
	}
	int tot=1,maxx=-1,tmp;
	for (int i=1;i<=n;i++)
	{
		int u=max(dp[0][i],dp[1][i]);
		if (u>maxx) maxx=u,tot=1,tmp=i;
		else if (u==maxx) tot++;	
	}
	if (maxx==-1||tot>1||min(dp[0][tmp],dp[1][tmp])==0) 
	{
		puts("0");
		return 0;
	}
	if (dp[0][tmp]==dp[1][tmp])
	{
		if (dp[0][tmp]%2==0) puts("1");
		else puts("0");
		return 0;
	}
	puts("0");
	return 0;
}