#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c;
}
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
char a[N];
bool out[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),cnt0=0;
		for (int i=1;i<=n;i++) cnt0+=(a[i]=get())=='0';
		if (n%2||cnt0%2)
		{
			puts("NO");
			continue;
		}
		bool flag=1;
		int cnt1=n-cnt0,now0=0,now1=0,top0=0,top1=0;
		for (int i=1;i<=n;i++)
		if (a[i]=='1')
		{
			now1++;
			if (now1<=cnt1/2)
			{
				top0++;
				top1++;
				out[i]=0;
			}
			else
			{
				if ((--top0)<0||(--top1)<0)
				{
					flag=0;
					break;
				}
				out[i]=1;
			}
		}
		else
		{
			now0++;
			if (now0&1)
			{
				top0++;
				if ((--top1)<0)
				{
					flag=0;
					break;
				}
				out[i]=0;
			}
			else
			{
				if ((--top0)<0)
				{
					flag=0;
					break;
				}
				top1++;
				out[i]=1;
			}
		}
		if (flag)
		{
			puts("YES");
			for (int i=1;i<=n;i++) putchar(out[i]?')':'(');
			puts("");
			for (int i=1;i<=n;i++) putchar((out[i]^(a[i]=='0'))?')':'(');
			puts("");
		}
		else puts("NO");
	}
	
	return 0;
}