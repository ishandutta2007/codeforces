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
int b[N],q[N];
bool a[N][N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),h=1,t=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		char c=getchar();
		while (c!='0'&&c!='1') c=getchar();
		a[i][j]=c-'0';
	}
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) if (!b[i]) q[++t]=i;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=1;i<=n;i++) if (a[now][i]) if (!--b[i]) q[++t]=i;
	}
	print(t);
	for (int i=1;i<=t;i++) print(q[i]," \n"[i==t]);
	
	return 0;
}