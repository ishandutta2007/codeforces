#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1e3;

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
int a[N];

int main()
{
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c<'0'||'9'<c) c=getchar();
		a[i]=c-'0';
	}
	bool flag=1;
	for (int j=k+1;j<=n;j++)
	if (a[j]>a[(j-1)%k+1])
	{
		flag=0;
		break;
	}
	else if (a[j]<a[(j-1)%k+1]) break;
	if (!flag)
	for (int i=k;i>=1;i--)
	{
		if (a[i]<9)
		{
			a[i]++;
			break;
		}
		a[i]=0;
	}
	print(n);
	a[0]=a[k];
	for (int i=1;i<=n;i++) putchar(a[i%k]+'0');

	return 0;
}