#include<bits/stdc++.h>
using namespace std;
int n,t,k;
int a[200001];
long long ans;
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
		n=read();
		a[1]=read();
		ans=0;
		for (int i=2;i<=n;i++) 
		{
			a[i]=read();
			if (a[i]<a[i-1]) ans+=a[i-1]-a[i];
		}
		cout << ans << endl;
	}
	return 0;
}