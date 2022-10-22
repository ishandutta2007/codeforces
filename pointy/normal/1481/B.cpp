#include<bits/stdc++.h>
using namespace std;
int t; 
int n,k;
int a[201];
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
	t=read();
	while (t--)
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=-1;
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<n;j++)
			{
				if (a[j]<a[j+1]) 
				{
					a[j]++;
					ans=j;
					goto fff;
				}
			}
			cout << -1 << endl;
			goto eee;
			fff:;
		}
		cout << ans << endl;
		eee:;
	}
	return 0;
}