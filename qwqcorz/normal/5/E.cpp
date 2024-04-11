#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
bool can[N];
int a[N],tot[N],st[N],top=0;

signed main()
{
	ll ans=0;
	int n=read(),Max=0;
	for (int i=1;i<=n;i++) Max=max(Max,a[i+n]=a[i]=read());
	for (int i=1;i<=n;i++)
	if (a[i]==Max)
	{
		for (int j=i;j<i+n;j++) a[j-i+1]=a[j];
		break;
	}
	Max=0;
	for (int i=n;i>=2;i--)
	{
		Max=max(Max,a[i]);
		can[i]=Max==a[i];
	}
	st[++top]=a[1];
	tot[top]=1;
	for (int i=2;i<=n;i++)
	{
		while (top>1&&st[top]<a[i]) ans+=tot[top--];
		if (st[top]==a[i])
		{
			if (top>2||(top==2&&tot[1]>1)) ans+=can[i];
			ans+=tot[top]+(top>1);
			tot[top]++;
		}
		else
		{
			if (top>1||(top==1&&tot[1]>1)) ans+=can[i];
			ans++;
			st[++top]=a[i];
			tot[top]=1;
		}
	}
	print(ans);

	return 0;
}