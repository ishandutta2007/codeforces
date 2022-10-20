#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int k=9;
const int S=1<<k;

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
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int a[N],n,ans[N];
void dfs(int now,int x,int y)
{
	if (now>n)
	{
		if (x==1&&y==1)
		{
			puts("YES");
			for (int i=1;i<=n;i++) print(ans[i],' ');
			exit(0);
		}
		return;
	}
	ans[now]=1; dfs(now+1,gcd(x,a[now]),y);
	ans[now]=2; dfs(now+1,x,gcd(y,a[now]));
}
bool dp[S][S];
int from[S][S][3],tot[2][k];
vector<int>factor(int x)
{
	vector<int>ret;
	for (int i=2;i*i<=x;i++)
	if (x%i==0)
	{
		ret.push_back(i);
		while (x%i==0) x/=i;
	}
	if (x>1) ret.push_back(x);
	return ret;
}
void get(int x,int y)
{
	if (!x&&!y) return;
	ans[from[x][y][1]]=from[x][y][0];
	if (from[x][y][0]==1) get(from[x][y][2],y);
					 else get(x,from[x][y][2]);
}
void solve(int x,int y)
{
	vector<int>fx=factor(a[x]),fy=factor(a[y]),A,B,id;
	int sx=fx.size(),sy=fy.size();
	for (int i=1;i<=n;i++)
	if (i!=x&&i!=y)
	{
		int u=0,v=0,flag=0;
		for (int j=0;j<sx;j++) if (a[i]%fx[j]) {u|=1<<j;if (tot[0][j]<k) flag=1;}
		for (int j=0;j<sy;j++) if (a[i]%fy[j]) {v|=1<<j;if (tot[1][j]<k) flag=1;}
		if (!flag) continue;
		for (int j=0;j<sx;j++) if (u>>j&1) tot[0][j]++;
		for (int j=0;j<sy;j++) if (v>>j&1) tot[1][j]++;
		A.push_back(u),B.push_back(v),id.push_back(i);
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=0;i<(int)A.size();i++)
	for (int x=(1<<sx)-1;x>=0;x--)
	for (int y=(1<<sy)-1;y>=0;y--)
	if (dp[x][y])
	{
		if ((x|A[i])>x&&!dp[x|A[i]][y])
		{
			dp[x|A[i]][y]=1;
			from[x|A[i]][y][0]=1;
			from[x|A[i]][y][1]=id[i];
			from[x|A[i]][y][2]=x;
		}
		if ((y|B[i])>y&&!dp[x][y|B[i]])
		{
			dp[x][y|B[i]]=1;
			from[x][y|B[i]][0]=2;
			from[x][y|B[i]][1]=id[i];
			from[x][y|B[i]][2]=y;
		}
	}
	if (dp[(1<<sx)-1][(1<<sy)-1])
	{
		ans[x]=1,ans[y]=2;
		get((1<<sx)-1,(1<<sy)-1);
		puts("YES");
		for (int i=1;i<=n;i++) print(ans[i]?ans[i]:1,' ');
		exit(0);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n<=(k+1)*2)
	{
		dfs(1,0,0);
		puts("NO");
		return 0;
	}
	for (int i=1;i<=10;i++) solve(1,rand()%(n-1)+2);
	puts("NO");
	
	return 0;
}