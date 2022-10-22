#include<bits/stdc++.h>
using namespace std;
int t;
int a[400005];
int n;
inline int read()
{
	char C;
	long long F=1,ANS=0;
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
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) 
		{
			char x;
			cin >> x;
			if (x=='L') a[i]=0;
			else a[i]=1;
		}
		int q=-1;
		for (int i=1;i<=n;i++) 
		{
			if (a[i]!=a[1]) 
			{
				q=i;
				break;
			}
		}
		if (q==-1)
		{
			cout << (n+2)/3 << endl;
			continue;
		}
		int len=0,ans=0;
		for (int i=q;i<=n+q;i++)
		{
			if ((i==n+q)||(i!=q&&a[(i-1)%n+1]!=a[(i-2)%n+1]))
			{
				ans+=len/3;
				len=0;
			}
			len++;
		}
		cout << ans << endl;
	}
	return 0;
}