#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int a[501][501],ans,k,n,m,cnt;
char s[501];
bool bo[50002];

struct node
{
	int wei,ans;
}f[50001];

const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int x,int y)
{
	a[x][y]=cnt; f[cnt].ans++;
	for (int i=0; i<=3; i++)
	{
		int xx=x+d[i][0],yy=y+d[i][1];
		if (xx>0&&xx<=n&&yy>0&&yy<=m&&a[xx][yy]==0) dfs(xx,yy);
	}
}

bool cmp(node a,node b) {return a.ans<b.ans;}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",&s);
		for (int j=0; j<m; j++)
			if (s[j]=='.') a[i][j+1]=0;
			else a[i][j+1]=-1;
	}
	memset(f,0,sizeof(f)); cnt=0;
	for (int i=1; i<=m; i++)
		if (a[1][i]==0) cnt++,dfs(1,i);
	for (int i=2; i<=n; i++)
		if (a[i][1]==0) cnt++,dfs(i,1);
	for (int i=2; i<=n; i++)
		if (a[i][m]==0) cnt++,dfs(i,m);
	for (int i=2; i<m; i++)
		if (a[n][i]==0) cnt++,dfs(n,i);
	cnt=n*m;
	for (int i=2; i<n; i++)
		for (int j=2; j<m; j++)
			if (a[i][j]==0) cnt++,dfs(i,j);
	for (int i=n*m+1; i<=cnt; i++) f[i].wei=i;
	f[cnt+1].ans=2147483647;
	sort(f+n*m+1,f+cnt+1,cmp);
	memset(bo,0,sizeof(bo));
	k=cnt-n*m-k;
	for (int i=n*m+1; i<=n*m+k; i++) 
		bo[f[i].wei]=1,ans+=f[i].ans;
	printf("%d\n",ans);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			if (a[i][j]==-1||bo[a[i][j]]) printf("*");
			else printf(".");
		printf("\n");
	}
	return 0;	
}