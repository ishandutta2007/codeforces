#include<bits/stdc++.h>
using namespace std;
const int N=1.5e3+5;
const int add=1145141;
const int mod=1919810111;

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
bool vis[N];
int a[N][N],b[N][N],ha[N],hb[N],p[N],n,m;
bitset<N>g[N],now;
vector<int>ans;
int Hash(int *a)
{
	int ret=0;
	for (int i=1;i<=m;i++) ret=(1505LL*ret+a[i]+add)%mod;
	return ret;
}
bool check()
{
	for (int i=1;i<=n;i++)
	{
		ha[i]=Hash(a[i]);
		hb[i]=Hash(b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		bool flag=0;
		for (int j=1;j<=n;j++) if (hb[i]==ha[j])
		{
			flag=1;
			p[i]=j;
			ha[j]=-1;
			break;
		}
		if (!flag) return 0;
	}
	for (int i=1;i<n;i++) if (!now[i]&&p[i]>p[i+1]) return 0;
	return 1;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) b[i][j]=read();
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++) g[i][j]=j==n||b[j][i]>b[j+1][i];
	now[n]=1;
	while (1)
	{
		bool flag=1;
		for (int i=1;i<=m;i++)
		if (!vis[i]&&(g[i]|now)==now)
		{
			ans.push_back(i);
			for (int j=1;j<n;j++) if (b[j][i]!=b[j+1][i]) now[j]=1;
			vis[i]=1;
			flag=0;
			break;
		}
		if (flag) break;
	}
	if (!check()) puts("-1");
	else
	{
		reverse(ans.begin(),ans.end());
		print(ans.size());
		for (int i:ans) print(i,' ');
	}
	
	return 0;
}