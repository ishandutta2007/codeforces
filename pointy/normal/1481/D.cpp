#include<bits/stdc++.h>
using namespace std;
int t; 
int n,m;
char a[1001][1001];
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
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j) continue;
				if (a[i][j]==a[j][i]) 
				{
					cout << "YES" << endl;
					for (int k=1;k<=m+1;k++)
					{
						if (k%2==1) cout << i << " ";
						else cout << j << " ";
					}
					cout << endl;
					return;
				}
			}
		}
		if (m%2==1) 
		{
			cout << "YES" << endl;
			for (int k=1;k<=m+1;k++)
			{
				if (k%2==1) cout << 1 << " ";
				else cout << 2 << " ";
			}
			cout << endl;
			return;
		}
		if (n==2)
		{
			cout << "NO" << endl;
			return;
		}
		cout << "YES" << endl; 
		for (int i=1;i<=3;i++)
		{
			for (int j=1;j<=3;j++)
			{
				if (i==j) continue;
				int K=6-i-j;
				if (i==K) continue;
				if (j==K) continue;
				if (a[i][j]==a[j][K])
				{
					if (a[K][i]==a[j][K])
					{
						for (int k=1;k<=m+1;k++)
						{
							cout << k%3+1 << " ";
						}
						cout << endl;
						return;
					}
					int u=(m+2)/2;
					for (int k=1;k<=m+1;k++)
					{
						if (k%3==u%3) cout << j << " ";
						else if (k%3==(u-1)%3) cout << i << " ";
						else cout << K << " ";
					}
					cout << endl;
					return;
				}
			}
		}
}
int main()
{
	t=read();
	while (t--)
	{
		work();
	}
	return 0;
}