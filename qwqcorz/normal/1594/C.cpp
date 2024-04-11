#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read();
		char c; cin>>c;
		scanf("%s",a+1);
		bool flag=1;
		for (int i=1;i<=n;i++) flag&=a[i]==c;
		if (flag){puts("0");continue;}
		flag=0;
		for (int i=n/2+1;i<=n;i++)
		if (a[i]==c)
		{
			flag=1;
			puts("1");
			print(i);
			break;
		}
		if (flag) continue;
		puts("2");
		print(n,' '),print(n-1);
	}
	
	return 0;
}