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
int a[3],b[3],A[3],B[3],p[10];
int calc1()
{
	int x[3],y[3];
	for (int i=0;i<3;i++) x[i]=a[i];
	for (int i=0;i<3;i++) y[i]=b[i];
	for (int i=1;i<=6;i++)
	if (p[i]<3)
	{
		int now=p[i];
		int j=(now+1)%3;
		int t=min(y[now],x[j]);
		y[now]-=t;
		x[j]-=t;
	}
	else
	{
		int now=p[i]-3;
		int t=min(x[now],y[now]);
		x[now]-=t;
		y[now]-=t;
	}
	int ret=0;
	for (int i=0;i<3;i++) ret+=x[i];
	return ret;
}
int calc2()
{
	int x[3],y[3],ret=0;
	for (int i=0;i<3;i++) x[i]=a[i];
	for (int i=0;i<3;i++) y[i]=b[i];
	for (int i=0;i<3;i++)
	{
		int j=(i+1)%3;
		ret+=min(x[i],y[j]);
	}
	return ret;
}

signed main()
{
	int n=read(),ans=1e9+7;
	for (int i=0;i<3;i++) A[i]=a[i]=read();
	for (int i=0;i<3;i++) B[i]=b[i]=read();
	for (int i=1;i<=6;i++) p[i]=i-1;
	do
	{
		ans=min(ans,calc1());
	}while (next_permutation(p+1,p+1+6));
	print(ans,' ');
	for (int i=0;i<3;i++) a[i]=A[i];
	for (int i=0;i<3;i++) b[i]=B[i];
	print(calc2());

	return 0;
}