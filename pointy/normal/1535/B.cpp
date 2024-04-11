#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N],b[N],cnt;

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
int ans;
void work()
{
	ans=0;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==0) b[++cnt]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==1) b[++cnt]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (__gcd(b[i],2*b[j])>1) ans++;
		}
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