#include<bits/stdc++.h>
using namespace std;
const int N=55;

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
bool check(int n)
{
	for (int i=2;i*i<=n;i++)
	if (n%i==0) return 1;
	return 0;
}
int cnt[10];
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		memset(cnt,0,sizeof(cnt));
		int n=read(),flag=0;
		scanf("%s",a+1);
		for (int i=1;i<=n;i++) cnt[a[i]-'0']++;
		for (int i=1;i<=n;i++)
		if (a[i]=='1'||a[i]=='4'||a[i]=='6'||a[i]=='8'||a[i]=='9')
		{
			puts("1");
			print(a[i]-'0');
			flag=1;
			break;
		}
		if (flag) continue;
		for (int i=1;i<=9;i++) if (cnt[i]>=2)
		{
			puts("2");
			write(i),print(i);
			flag=1;
			break;
		}
		if (flag) continue;
		for (int i=1;i<(1<<n);i++)
		{
			int s=0;
			for (int j=1;j<=n;j++)
			if (i>>(j-1)&1) s=s*10+a[j]-'0';
			if (check(s))
			{
				print(__builtin_popcount(i));
				print(s);
				break;
			}
		}
	}
	
	return 0;
}