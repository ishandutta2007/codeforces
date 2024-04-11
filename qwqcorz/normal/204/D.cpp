#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int p=1e9+7;

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
char s[N];
int f[N][2][2],g[N][2][2],a[N],pre[N][2];
int sum(int l,int r,int x,int y)
{
	if (l>r) return 0;
	return (g[r][x][y]-g[l-1][x][y]+p)%p;
}

signed main()
{
	int n=read(),k=read(),answer=1;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]=='X'?-1:s[i]=='B'?0:1;
	for (int i=1;i<=n;i++) if (s[i]=='X') answer=answer*2LL%p;
	for (int i=1;i<=n;i++) if (a[i]==0||a[i]==-1) pre[i][0]=pre[i-1][0]; else pre[i][0]=i;
	for (int i=1;i<=n;i++) if (a[i]==1||a[i]==-1) pre[i][1]=pre[i-1][1]; else pre[i][1]=i;
	f[0][0][0]=f[0][1][0]=g[0][0][0]=g[0][1][0]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=1)
			f[i][0][0]=sum(max(pre[i][0],i-k+1),i-1,1,0),
			f[i][0][1]=(sum(pre[i][0],i-1,1,1)+sum(pre[i][0],i-k,1,0))%p;
		if (a[i]!=0)
			f[i][1][0]=sum(pre[i][1],i-1,0,0),
			f[i][1][1]=sum(max(pre[i][1],i-k+1),i-1,0,1);
		for (int j=0;j<=1;j++)
		for (int k=0;k<=1;k++)
		g[i][j][k]=(g[i-1][j][k]+f[i][j][k])%p;
	}
	int ans=0;
	for (int j=0;j<=1;j++)
	for (int k=0;k<=1;k++) ans=(ans+f[n][j][k])%p;
	print((answer-ans+p)%p);
	
	return 0;
}