#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;

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
inline void up(int &x,int y){x=min(x,y);}
int f[N][N],a[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	memset(f,0x3f,sizeof(f));
	int T=read(),inf=f[0][0];
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[i]=read()+i;
		for (int i=1;i<=n;i++)
		{
			if (i==1) f[1][1]=0;
			else for (int j=i-1,now=0;j>=1;j--) if (a[j]>=i) up(f[i][a[j]],f[j][i-1]+now++);
			for (int j=1;j<=n;j++) up(f[i][j],f[i][j-1]);
		}
		print(f[n][n]);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) f[i][j]=inf;
	} 
	
	return 0;
}