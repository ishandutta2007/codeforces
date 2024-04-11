#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int K=26;
const int S=(1<<22)+5;

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
char a[N];
int d[K],e[K][K];
int pre[K],pos[K];
bool vis[K];
bool cmp(int x,int y)
{
	return pre[x]<pre[y];
}
int f[S];

signed main()
{
	int n=read(),k=read(),T=read(),ans=0;
	for (int i=1;i<=k;i++) pre[i]=n+1;
	for (int i=1;i<=k;i++) pos[i]=i;
	scanf("%s",a+1);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) vis[a[i]-'A'+1]=1;
	for (int i=1;i<=k;i++) d[i]=read();
	for (int i=1;i<=k;i++)
	for (int j=1;j<=k;j++) e[i][j]=read();
	for (int i=n;i>=1;i--)
	{
		int S=0;
		sort(pos+1,pos+1+k,cmp);
		for (int j=1;j<=k&&pre[pos[j]]<=n;j++)
		{
			int x=a[i]-'A',y=a[pre[pos[j]]]-'A';
			f[S]+=e[x+1][y+1];
			f[S|(1<<x)]-=e[x+1][y+1];
			f[S|(1<<y)]-=e[x+1][y+1];
			f[S|(1<<x)|(1<<y)]+=e[x+1][y+1];
			S|=1<<y;
		}
		pre[a[i]-'A'+1]=i;
	}
	for (int j=0;j<k;j++)
	for (int i=0;i<(1<<k);i++)
	if (i&(1<<j)) f[i]+=f[i^(1<<j)];
	for (int S=0;S<(1<<k);S++)
	{
		bool flag=0;
		for (int i=1;i<=k;i++) if (S&(1<<(i-1))) if (!vis[i])
		{
			flag=1;
			break;
		}
		if (flag) continue;
		flag=1;
		for (int i=1;i<=k;i++) if (!(S&(1<<(i-1)))) if (vis[i]) flag=0;
		if (flag) continue;
		ll now=f[S];
//		print(now,' ');
		for (int i=1;i<=k;i++) if (S&(1<<(i-1))) now+=d[i];
//		print(now);
		if (now<=T) ans++;
	}
	print(ans);

	return 0;
}