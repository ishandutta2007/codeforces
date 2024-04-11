#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
const int N=4e3+5;

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
vector<int>v[N],nxt[N];
pair<int,int>a[N];
int b[N],dp[N],Max[N],pre[N],now[N];
bool cmp(int x,int y)
{
	return a[x].l>a[y].l;
}
void Print(int x,int n)
{
	if (x!=n) print(x,' ');
	for (int i=0;i<nxt[x].size();i++) Print(nxt[x][i],n);
}

signed main()
{
	memset(dp,0,sizeof(dp));
	int n=read(),cnt=0,ans=1;
	for (int i=1;i<=n;i++)
	{
		int c=read(),r=read();
		a[i].l=c-r;
		a[i].r=c+r;
		b[++cnt]=c-r;
		b[++cnt]=c+r;
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++)
	{
		a[i].l=lower_bound(b+1,b+1+cnt,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+1+cnt,a[i].r)-b;
	}
	n++;
	a[n].l=1;
	a[n].r=cnt;
	for (int i=1;i<=n;i++) v[a[i].r].push_back(i);
	for (int i=1;i<=cnt;i++) sort(v[i].begin(),v[i].end(),cmp);
	for (int i=1;i<=cnt;i++)
	for (int j=0;j<v[i].size();j++)
	{
		for (int k=1;k<=i;k++)
		{
			pre[k]=k-1;
			now[k]=0;
			Max[k]=Max[k-1];
			for (int t=0;t<v[k].size();t++)
			if (a[v[k][t]].l>=a[v[i][j]].l)
			if (Max[k]<Max[a[v[k][t]].l]+dp[v[k][t]])
			{
				Max[k]=Max[a[v[k][t]].l]+dp[v[k][t]];
				pre[k]=a[v[k][t]].l;
				now[k]=v[k][t];
			}
		}
		dp[v[i][j]]=Max[i]+1;
		int x=i;
		while (x)
		{
			if (now[x]) nxt[v[i][j]].push_back(now[x]);
			x=pre[x];
		}
		if (dp[ans]<dp[v[i][j]]) ans=v[i][j];
	}
	print(dp[ans]-1);
	Print(ans,n);

	return 0;
}