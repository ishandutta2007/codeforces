#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int a[N],R[N];
char c[N];

signed main()
{
	a[0]=0;
	scanf("%s",c+2);
	int n=strlen(c+2)+2;
	c[1]='0';
	c[n]='1';
	for (int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		if (c[i]=='0') a[i]++;
				  else a[i]--;
	}
	R[n+1]=-1919810;
	for (int i=n;i>=1;i--) R[i]=max(R[i+1],a[i]);
	for (int i=1,Max=-1919810,tag=0;i<=n;i++)
	if (c[i]=='1')
	{
//		print(Max);
		if (Max==a[i]+tag+1&&R[i+1]<=a[i])
		{
			c[i]='0';
			tag+=2;
		}
		Max=max(Max,a[i]+tag);
	}
	else Max=max(Max,a[i]+tag);
	for (int i=2;i<n;i++) putchar(c[i]);

	return 0;
}