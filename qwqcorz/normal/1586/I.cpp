#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;

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
char a[N][N];
int c[N][N],id[N][N],col[N];

signed main()
{
	memset(col,-1,sizeof(col));
	int n=read();
	if (n&1) return puts("NONE"),0;
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	if (i&1)
	{
		for (int j=1;j<=i;j++)
			id[j][i-j+1]=(i+1)/2,
			c[j][i-j+1]=min(j-1,i-j)&1;
		for (int j=i+1;j<=n;j++)
			id[j][j-i]=(i+1)/2,
			c[j][j-i]=min(j-i-1,n-j)&1;
	}
	else
	{
		for (int j=1;j<=n-i+1;j++)
			id[j][i+j-1]=(i+1)/2,
			c[j][i+j-1]=min(j-1,n-i+1-j)&1;
		for (int j=n-i+2;j<=n;j++)
			id[j][n+n-j-i+2]=(i+1)/2,
			c[j][n+n-j-i+2]=min(j-(n-i+1)-1,n-j)&1;
	}
	/*
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	print(id[i][j]," \n"[j==n]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	print(c[i][j]," \n"[j==n]);
	*/
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (a[i][j]!='.')
	{
		int x=id[i][j],y=(a[i][j]=='S')^c[i][j];
		if (!~col[x]) col[x]=y;
		else if (col[x]!=y) return puts("NONE");
	}
	for (int i=1;i<=n/2;i++) if (!~col[i]) return puts("MULTIPLE");
	puts("UNIQUE");
	for (int i=1;i<=n;i++,putchar('\n'))
	for (int j=1;j<=n;j++)
	putchar("GS"[col[id[i][j]]^c[i][j]]);
	
	return 0;
}