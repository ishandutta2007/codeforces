#include<bits/stdc++.h>
#define int long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],f[N],g[N];
pair<int,int>s[N];

signed main()
{
	s[0].fi=0;
	int n=read(),ans=1;
	for (int i=1;i<=n;i++) a[i]=read();
	int top=1;
	f[1]=a[1];
	s[1]=mk(a[1],1);
	for(int i=2;i<=n;i++)
	{
		int tot=1,now=f[i-1];
		while(top&&s[top].fi>a[i])
		{
			tot+=s[top].se;
			now-=s[top].se*s[top].fi;
			top--;
		}
		now+=tot*a[i];
		s[++top]=mk(a[i],tot);
		f[i]=now;
	}
	g[n]=a[n];
	s[top=1]=mk(a[n],1);
	for(int i=n-1;i>=1;i--)
	{
		int tot=1,now=g[i+1];
		while(top&&s[top].fi>a[i])
		{
			tot+=s[top].se;
			now-=s[top].se*s[top].fi;
			top--;
		}
		now+=tot*a[i];
		s[++top]=mk(a[i],tot);
		g[i]=now;
	}
	for (int i=1;i<=n;i++)
	if (f[i]+g[i]-a[i]>f[ans]+g[ans]-a[ans])
	ans=i;
	for (int i=ans;i>=2;i--) a[i-1]=min(a[i-1],a[i]);
	for (int i=ans;i<n;i++) a[i+1]=min(a[i+1],a[i]);
	for (int i=1;i<=n;i++) print(a[i],' ');

	return 0;
}