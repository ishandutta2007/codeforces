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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool check(int x,int d)
{
	for (;x;x/=10) if (x%10==d) return 1;
	return 0;
}
int f[1000][10];
void Multi_test_no_horses()
{
	int n=read(),d=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x>999) puts("YES");
			  else puts(f[x][d]?"YES":"NO");
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	for (int d=1;d<=9;d++)
	for (int i=f[0][d]=1;i<1000;i++)
	for (int j=1;j<=i;j++)
	if (f[i-j][d]&&check(j,d))
	{
		f[i][d]=1;
		break;
	}
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}