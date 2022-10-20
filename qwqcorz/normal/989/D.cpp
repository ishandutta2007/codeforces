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
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(long long x,char c='\n')
{
	write(x);
	putchar(c);
}
int x1[N],x2[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	long long ans=0;
	int n=read(),L=read(),w=read(),n1=0,n2=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),v=read();
		if (v>0) x1[++n1]=x;
			else x2[++n2]=x;
	}
	sort(x1+1,x1+1+n1);
	sort(x2+1,x2+1+n2);
	for (int i=1,j=1;i<=n1;i++)
	{
		while (j<=n2&&1LL*w*(x2[j]+L-x1[i])<=abs(x1[i]+x2[j]+L)) j++;
		ans+=n2-j+1;
	}
	print(ans);
	
	return 0;
}