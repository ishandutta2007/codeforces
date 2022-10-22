#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],ans,c[200005]; 
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
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
		for (int i=2;i<=n;i++) b[i]=abs(b[i]);
		ans=0;
		for (int i=2;i<=n;i++) ans+=b[i];
		long long tot=ans;
		for (int i=2;i<n;i++)
		{
			ans=min(ans,tot-b[i]-b[i+1]+abs(a[i+1]-a[i-1]));
		}
		ans=min(ans,tot-b[2]);
		ans=min(ans,tot-b[n]);
		cout << ans << endl;
	}
 	return 0;
}