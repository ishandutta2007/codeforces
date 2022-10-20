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
char a[28];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<=n;i++)
	if ((i==1&&a[i]=='9')||a[i]<'5') putchar(a[i]);
								else putchar(9-(a[i]-'0')+'0');

	return 0;
}