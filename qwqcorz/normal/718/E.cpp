#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int C=8;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(long long x,char c='\n')
{
	write(x);
	putchar(c);
}
int ans=-1;
long long ans2=0;
void up(int x,int y)
{
	if (x==ans) ans2+=y;
	else if (x>ans) ans=x,ans2=y;
}
vector<int>pos[C];
char a[N];
int disv[N][C],disc[C][C];
int tot[C][1<<C];

signed main()
{
	memset(disv,0x3f,sizeof(disv));
	memset(disc,0x3f,sizeof(disc));
	static const int inf=disv[0][0];
	int n=read();
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) pos[a[i]-='a'].push_back(i);
	for (int j=0;j<8;j++)
	{
		static bool vis[C];
		memset(vis,0,sizeof(vis));
		queue<int>q;
		for (int i:pos[j]) disv[i][j]=0,q.push(i);
		while (!q.empty())
		{
			int i=q.front(); q.pop();
			if (i>1&&disv[i-1][j]==inf) disv[i-1][j]=disv[i][j]+1,q.push(i-1);
			if (i<n&&disv[i+1][j]==inf) disv[i+1][j]=disv[i][j]+1,q.push(i+1);
			if (vis[a[i]]) continue;
			vis[a[i]]=1;
			for (int to:pos[a[i]]) if (disv[to][j]==inf) disv[to][j]=disv[i][j]+1,q.push(to);
		}
	}
	for (int j=0;j<8;j++)
	for (int i=1;i<=n;i++)
	disc[a[i]][j]=min(disc[a[i]][j],disv[i][j]);
	for (int i=1;i<=n;i++)
	for (int k=max(i-15,1);k<i;k++)
	{
		int dis=i-k;
		for (int j=0;j<8;j++) dis=min(dis,disv[i][j]+disv[k][j]+1);
		up(dis,1);
	}
	for (int i=17;i<=n;i++)
	{
		int st=0;
		for (int j=0;j<8;j++) st|=(disv[i-16][j]-disc[a[i-16]][j])<<j;
		tot[a[i-16]][st]++;
		for (int j=0;j<8;j++)
		for (int k=0;k<(1<<8);k++)
		if (tot[j][k])
		{
			int dis=15;
			for (int c=0;c<8;c++) dis=min(dis,disv[i][c]+disc[j][c]+(k>>c&1)+1);
			up(dis,tot[j][k]);
		}
	}
	print(ans,' '),print(ans2);
	
	return 0;
}