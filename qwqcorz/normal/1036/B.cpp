#include<bits/stdc++.h>
#define int long long
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

signed main()
{
	int T=read();
	while (T--)
	{
		int x=read(),y=read(),k=read();
		int t1=min(x,y),t2=max(x,y)-t1,ans1=t1+t2-t2%2,ans2=t2%2;
		if ((t1+t2)%2!=k%2)
		{
			if (t2%2==0)
			{
				ans1--;
				ans2+=2;
			}
			else
			{
				ans1++;
			}
		}
//		print(t1,',');print(t2);
		if (max(x,y)>k) print(-1);
				   else print(ans1+k-(ans1+ans2));
	}

	return 0;
}