#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int X=1e8+2;
const int M=2e8+5;

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
bitset<M>t;
int a[N],ans[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(); a[i]=1;
		if (x<0) a[i]=-1,x=-x;
		for (int j=2;j*j<=x;j++)
		{
			bool flag=0;
			while (x%j==0) x/=j,flag^=1;
			if (flag) a[i]*=j;
		}
		a[i]*=x;
	}
	for (int i=1;i<=n;i++)
	{
		int now=0,flag=0;
		for (int j=i;j<=n;j++) flag|=!a[j],ans[max((now+=!t[a[j]+X])-flag,1)]++,t[a[j]+X]=1;
		for (int j=i;j<=n;j++) t[a[j]+X]=0;
	}
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}