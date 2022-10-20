#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
bool a[N],b[N];

int main()
{
	int n=read(),s1=0,s2=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (a[i]>b[i]) s1++;
		if (a[i]<b[i]) s2++;
	}
	if (s1==0) print(-1);
		  else print(s2/s1+1);

	return 0;
}