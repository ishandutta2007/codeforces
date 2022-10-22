#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=200007;
int n,m,T; 
int a[N];
int b[N],c[N],s[N];

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
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int cnt=0;
	for (int i=1;i<=n;i++) b[i]=0,c[i]=0;
	for (int i=1;i<=n;i++)
	{
		if (i==1||a[i]!=a[i-1]) 
		{
			b[++cnt]=1;
		}
		else b[cnt]++;
	}
	for (int i=1;i<=cnt;i++) c[b[i]]++;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	int ans=100000000;
	for (int i=1;i<=n;i++) 
	{
		ans=min(ans,n-(s[n]-s[i])*i-c[i]*i);
	}
	cout << ans << endl;
	return;
}
int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}