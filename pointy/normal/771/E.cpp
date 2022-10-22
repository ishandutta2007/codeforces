#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=3e5+5;
ll a[3][N],s[3][N];
int pre[3][N];
map<ll,ll>q;
map<int,int>dp[N];
int ask(int i,int j)
{
	if (i<0||j<0) return -1;
	if (i==0&&j==0) return 0;
	if (dp[i][j]) return dp[i][j];
	int res=0;
	if (pre[1][i]>pre[2][j]) res=max(res,ask(pre[1][i]-1,j)+1);
	else res=max(res,ask(i,pre[2][j]-1)+1);
	int u=min(i,j);
	if (pre[0][u]!=0) res=max(res,ask(pre[0][u]-1,pre[0][u]-1)+1);
	dp[i][j]=res;
	return res;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
	for (int i=1;i<=2;i++) 
	{
		q.clear();
		q[0]=1;
		for (int j=1;j<=n;j++)
		{
			a[i][j]=read();
			s[i][j]=s[i][j-1]+a[i][j];
			pre[i][j]=q[s[i][j]];
			q[s[i][j]]=j+1;
		}
	}
	for (int i=0;i<=0;i++)
	{
		q.clear();
		q[0]=1;
		for (int j=1;j<=n;j++)
		{
			a[i][j]=a[1][j]+a[2][j];
			s[i][j]=s[i][j-1]+a[i][j];
			pre[i][j]=q[s[i][j]];
			q[s[i][j]]=j+1;
		}
	}
	for (int i=0;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			pre[i][j]=max(pre[i][j],pre[i][j-1]);
		}
	}
	printf("%d\n",ask(n,n));
	
	return 0;
}