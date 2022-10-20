#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int a[N],c[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=1,sum1=0,sum=0; c[1]=1;
	for (int i=1;i<=n;i++) sum+=a[i]=read(); sum1=a[1];
	for (int i=2;i<=n;i++) if (a[1]>=a[i]*2) c[++m]=i,sum1+=a[i];
	if (sum1>=sum/2+1)
	{
		print(m);
		for (int i=1;i<=m;i++) print(c[i]," \n"[i==m]);
	}
	else puts("0");
	
	return 0;
}