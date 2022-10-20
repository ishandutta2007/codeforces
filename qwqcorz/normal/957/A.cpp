#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

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

signed main()
{
	int n=read();
	scanf("%s",a+1);
	for (int i=1;i<n;i++) if (a[i]==a[i+1]&&a[i]!='?') return puts("No");
	for (int i=1;i<=n-1;i++) if (a[i]=='?'&&a[i+1]=='?') return puts("Yes");
	for (int i=1;i<=n-2;i++) if (a[i]!='?'&&a[i+2]!='?'&&a[i+1]=='?'&&a[i]==a[i+2]) return puts("Yes");
	if (a[1]=='?'||a[n]=='?') return puts("Yes");
	puts("No");

	return 0;
}