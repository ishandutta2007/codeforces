#include<bits/stdc++.h>
using namespace std;
int a[2001][2001]; 
int p[2][2001][10],q[2][2001][10],ans[10];
int P[11],Q[11];
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
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				char x;
				cin >> x;
				a[i][j]=x-'0';
			}
		}
		memset(ans,0,sizeof(ans));
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<10;j++) p[0][i][j]=-1,q[0][i][j]=-1;
			for (int j=1;j<=n;j++)
			{
				if (p[0][i][a[i][j]]==-1) p[0][i][a[i][j]]=j;
			}
			for (int j=n;j>=1;j--)
			{
				if (q[0][i][a[i][j]]==-1) q[0][i][a[i][j]]=j;
			}
			for (int j=0;j<=9;j++)
			{
				if (p[0][i][j]!=-1&&q[0][i][j]!=p[0][i][j]) ans[j]=max(ans[j],(q[0][i][j]-p[0][i][j])*max(i-1,n-i));
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<10;j++) p[1][i][j]=-1,q[1][i][j]=-1;
			for (int j=1;j<=n;j++)
			{
				if (p[1][i][a[j][i]]==-1) p[1][i][a[j][i]]=j;
			}
			for (int j=n;j>=1;j--)
			{
				if (q[1][i][a[j][i]]==-1) q[1][i][a[j][i]]=j;
			}
			for (int j=0;j<=9;j++)
			{
				if (p[1][i][j]!=-1&&q[1][i][j]!=p[1][i][j]) ans[j]=max(ans[j],(q[1][i][j]-p[1][i][j])*max(i-1,n-i));
			}
		}
		for (int i=0;i<=9;i++) P[i]=-1,Q[i]=-1;
		for (int i=n;i>=1;i--)
		{
			for (int j=1;j<=n;j++)
			{
				if (P[a[j][i]]==-1) P[a[j][i]]=i;
			}
		}
		for (int i=n;i>=1;i--)
		{
			for (int j=1;j<=n;j++)
			{
				if (Q[a[i][j]]==-1) Q[a[i][j]]=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (P[a[i][j]]!=-1&&P[a[i][j]]!=j) ans[a[i][j]]=max(ans[a[i][j]],(P[a[i][j]]-j)*max(i-1,n-i));
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (Q[a[i][j]]!=-1&&Q[a[i][j]]!=i) ans[a[i][j]]=max(ans[a[i][j]],(Q[a[i][j]]-i)*max(j-1,n-j));
			}
		}
		for (int i=0;i<=9;i++) P[i]=-1,Q[i]=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (P[a[j][i]]==-1) P[a[j][i]]=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (Q[a[i][j]]==-1) Q[a[i][j]]=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (P[a[i][j]]!=-1&&P[a[i][j]]!=j) ans[a[i][j]]=max(ans[a[i][j]],(j-P[a[i][j]])*max(i-1,n-i));
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (Q[a[i][j]]!=-1&&Q[a[i][j]]!=i) ans[a[i][j]]=max(ans[a[i][j]],(i-Q[a[i][j]])*max(j-1,n-j));
			}
		}
		for (int i=0;i<=9;i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}