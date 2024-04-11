#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void solve()
{
	int x=1,y=1,cnt=0;
	string s;
	for (int d=1;;d=-d)
	{
		bool flag=0,flag2=0;
		for (int i=1;i<8;i++)
		{
			cin>>s;
			if (s=="Done") return;
			flag2|=s.find("Up")!=s.npos;
			if (s.find("Down")!=s.npos&&!flag)
			{
				cout<<++x<<' '<<y<<endl;
				flag=1,i--;
				continue;
			}
			if (i+1==8&&!flag2&&!flag&&x<8)
			{
				cout<<++x<<' '<<y<<endl;
				flag=1,i--;
				continue;
			}
			cout<<x<<' '<<(y+=d)<<endl;
		}
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		puts("1 1");
		fflush(stdout);
		solve();
	}
	
	return 0;
}