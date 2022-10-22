#include<bits/stdc++.h>
using namespace std;
long long n,t,k;
int a[200001];
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
	t=read();
	while (t--)
	{
		cin >> n >> k;
		int maxx=-2e9,minn=2e9;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();
			maxx=max(a[i],maxx);
			minn=min(minn,a[i]);
		}
		for (int i=1;i<=n;i++) a[i]=maxx-a[i];
		if (k%2==1) 
		{
			for (int i=1;i<=n;i++) cout << a[i] << " ";
			cout << endl;
		}
		else
		{
			for (int i=1;i<=n;i++) cout << maxx-minn-a[i] << " ";
			cout << endl;
		}
	}
	return 0;
}