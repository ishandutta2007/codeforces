#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T,n; 
int a[3005];
ll l[3005][3005],r[3005][3005],ans;
inline int read()
{
	char C;
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
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				l[i][j]=0,r[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (a[i]==a[j]) 
				{
					l[i][j]=1,r[j][i]=1;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				r[i][j]+=r[i][j-1];
			}
			for (int j=n;j>=1;j--)
			{
				l[i][j]+=l[i][j+1];
			}	
		}
		ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ans=ans+l[i][j+1]*r[j][i-1];
			}
		}
		cout << ans << endl;
	}
	return 0;
}