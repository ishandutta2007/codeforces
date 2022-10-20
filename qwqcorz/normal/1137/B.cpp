#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int inf=1e9+7;

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
char a[N],b[N];
int kmp[N];

signed main()
{
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	int x0=0,y0=0;
	for (int i=1;i<=n;i++)
	if (a[i]=='0') x0++;
			  else y0++;
	for (int i=1;i<=m;i++)
	if (b[i]=='0') x0--;
			  else y0--;
	if (x0<0||y0<0)
	{
		for (int i=1;i<=n;i++) putchar(a[i]);
		return 0;
	}
	/////////////////////////////////////
	for (int i=2,j=0;i<=m;i++)
	{
		while (j&&b[j+1]!=b[i]) j=kmp[j];
		if (b[j+1]==b[i]) j++;
		kmp[i]=j;
	}
	int x1=0,y1=0;
	for (int i=kmp[m]+1;i<=m;i++)
	if (b[i]=='0') x1++;
			  else y1++;
	/////////////////////////////////////
	reverse(b+1,b+1+m);
	/////////////////////////////////////
	for (int i=2,j=0;i<=m;i++)
	{
		while (j&&b[j+1]!=b[i]) j=kmp[j];
		if (b[j+1]==b[i]) j++;
		kmp[i]=j;
	}
	int x2=0,y2=0;
	for (int i=kmp[m]+1;i<=m;i++)
	if (b[i]=='0') x2++;
			  else y2++;
	/////////////////////////////////////
	reverse(b+1,b+1+m);
	/////////////////////////////////////
	int x=0,y=0,ans=0;
	for (int i=0;i<=n/(x1+y1);i++)
	if (i*x1<=x0&&i*y1<=y0)
	{
		int tmpx=x0-i*x1,tmpy=y0-i*y1,tmp=min(x2?tmpx/x2:inf,y2?tmpy/y2:inf);
		if (i+tmp>ans)
		{
			x=i;
			y=tmp;
			ans=i+tmp;
		}
	}
	x0-=x*x1+y*x2;
	y0-=x*y1+y*y2;
	for (int i=1;i<=y;i++)
	for (int j=1;j<=x2+y2;j++)
	putchar(b[j]);
	for (int i=1;i<=m;i++) putchar(b[i]);
	for (int i=1;i<=x;i++)
	for (int j=m-x1-y1+1;j<=m;j++)
	putchar(b[j]);
	for (int i=1;i<=x0;i++) putchar('0');
	for (int i=1;i<=y0;i++) putchar('1');

	return 0;
}