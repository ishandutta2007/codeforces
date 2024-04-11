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
void Print(int x)
{
	puts("YES");
	print(x);
	exit(0);
}
char c[N];
int a[N];

signed main()
{
	scanf("%s",c+1);
	int n=strlen(c+1);
	for (int i=1;i<=n;i++) a[i]=c[i]-'0';
	for (int i=1;i<=n;i++) if (a[i]%8==0) Print(a[i]);
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int now=a[i]*10+a[j];
		if (now%8==0) Print(now);
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	for (int k=j+1;k<=n;k++)
	{
		int now=a[i]*100+a[j]*10+a[k];
		if (now%8==0) Print(now);
	}
	puts("NO");

	return 0;
}