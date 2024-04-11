#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read()
{
	ll s=0;
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
ll u,v;
int main()
{
	ll u=read(),v=read();

	if (v<u||(v-u)&1) return printf("-1\n"),0;
	if(!u)
	{
		if(!v) return printf("%lld\n",u),0;
		return printf("2\n%lld %lld\n",v/2,v/2),0;
	}
	if(u==v) return printf("1\n%lld",u),0;
	if(u&((v-u)/2)) return printf("3\n%lld %lld %lld",u,(v-u)/2,(v-u)/2),0;
	printf("2\n%lld %lld",u+(v-u)/2,(v-u)/2);

	return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;

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
int ans[70],a[10];

signed main()
{
	memset(a,0,sizeof(a));
	memset(ans,0,sizeof(ans));
	int u=read(),v=read(),now=0,Max=0;
	if (u>v) return print(-1),0;
	bool add=0;
	while (u||v)
	{
		bool x=u&1,y=v&1;
		u>>=1;
		v>>=1;
		now++;
		if (add==0)
		{
			if (x==0&&y==0) ;
			if (x==0&&y==1) ans[now-1]+=2;
			if (x==1&&y==0)
			{
				ans[now]=1;
				ans[now-1]+=2;
				add=1;
			}
			if (x==1&&y==1) ans[now]=1;
		}
		if (add==1)
		{
			add=0;
			if (x==0&&y==0)
			{
				ans[now-1]+=2;
				add=1;
			}
			if (x==0&&y==1) ;
			if (x==1&&y==0)
			{
				ans[now]=1;
				add=1;
			}
			if (x==1&&y==1)
			{
				ans[now]=1;
				ans[now-2]+=2;
				add=1;
			}
		}
	}
	if (ans[0]||add) return print(-1),0;
	for (int i=1,b=1;i<=now;i++,b<<=1)
	{
		for (int j=1;j<=ans[i];j++) a[j]|=b;
		Max=max(Max,ans[i]);
	}
	print(Max);
	for (int i=1;i<=Max;i++) print(a[i],' ');

	return 0;
}
*/