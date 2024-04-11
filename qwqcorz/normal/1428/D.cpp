#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 

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
int x[N],y[N],ans=0,a[N],one[N],cnt=0;
bool vis[N];
void add(int X,int Y)
{
	ans++;
	x[ans]=X;
	y[ans]=Y;
}

signed main()
{
	memset(vis,0,sizeof(vis));
	int n=read(),now=0;
	for (int i=1;i<=n;i++) a[i]=read();
	int lst=0,tmp=0;
	for (int i=1;i<=n;i++)
	if (a[i]==3)
	{
		if (lst) add(now,i);
		lst=i;
		now++;
		add(now,i);
		tmp=now;
	}
	for (int i=n;i>=1;i--)
	{
		if (a[i]==1) one[++cnt]=i;
		if (a[i]==2)
		{
			if (cnt==0) return puts("-1"),0;
			now++;
			add(now,i);
			add(now,one[cnt]);
			vis[i]=1;
			vis[one[cnt]]=1;
			cnt--;
		}
	}
	for (int i=lst+1;i<=n;i++)
	if (a[i]==2)
	{
		if (lst) add(tmp,i);
		lst=0;
	}
	for (int i=lst+1;i<=n;i++)
	if (!vis[i]&&a[i]==1)
	{
		if (lst) add(tmp,i);
		lst=0;
	}
	for (int i=1;i<=n;i++)
	if (!vis[i]&&a[i]==1)
	{
		now++;
		add(now,i);
	}
	if (lst) return puts("-1"),0;
	print(ans);
	for (int i=1;i<=ans;i++)
	{
		print(x[i],' ');
		print(y[i]);
	}

	return 0;
}