#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200008;
int n,m; 
char a[N],b[N];
int dp1[N],dp2[N];

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
	n=read(),m=read();
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++) cin >> b[i];
	int tp=1;
	for (int i=1;i<=m;i++)
	{
		while (b[i]!=a[tp]) 
		{
			tp++;
		}
		dp1[i]=tp;
		tp++;
	}
	tp=n;
	for (int i=m;i>=1;i--)
	{
		while (b[i]!=a[tp]) 
		{
			tp--;
		}
		dp2[i]=tp;
		tp--;
	}
	int ans=0;
	for (int i=1;i<m;i++)
	{
		ans=max(ans,dp2[i+1]-dp1[i]);
	}
	cout << ans;
	return;
}

int main()
{
	work();
	return 0;
}