#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int M=300;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

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
int id[N][N],cnt=0,n,m,d;
pair<int,int>pos[M];
int vis[N][N],dis[N][N];
vector<int>h[N][N];
vector<pair<int,int>>who[M];
void bfs(int x,int y,int col)
{
	queue<pair<int,int>>q;
	q.push(make_pair(x,y));
	dis[x][y]=0;
	while (!q.empty())
	{
		int x=q.front().first,y=q.front().second; q.pop();
		h[x][y].push_back(col);
		who[col].push_back(make_pair(x,y));
		if (dis[x][y]==d) continue;
		for (int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if (a[nx][ny]=='X') continue;
			if (vis[nx][ny]==col) continue;
			vis[nx][ny]=col;
			dis[nx][ny]=dis[x][y]+1;
			q.push(make_pair(nx,ny));
		}
	}
}
bool check(const vector<pair<int,int>>&a,const vector<pair<int,int>>&b)
{
	for (int i=0,j=0;i<(int)a.size();i++)
	{
		while (j+1<(int)b.size()&&b[j+1]<=a[i]) j++;
		if (a[i]==b[j]) return 0;
	}
	return 1;
}
vector<bitset<M>>get(const vector<pair<int,int>>&a)
{
	vector<bitset<M>>ret;
	for (auto i:a)
	{
		bitset<M>tmp;
		for (int j:h[i.first][i.second]) tmp.set(j);
		ret.push_back(tmp);
	}
	return ret;
}
void solve(const vector<pair<int,int>>&a,const vector<pair<int,int>>&b)
{
	auto A=get(a),B=get(b);
	for (int i=0;i<(int)A.size();i++)
	for (int j=0;j<(int)B.size();j++)
	if ((int)(A[i]|B[j]).count()==cnt)
	{
		print(a[i].first,' ');
		print(a[i].second,' ');
		print(b[j].first,' ');
		print(b[j].second);
		return;
	}
	puts("-1");
}
void solve(const vector<pair<int,int>>&a)
{
	auto A=get(a);
	if ((int)A.size()==1&&(int)A[0].count()==cnt)
	{
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (i!=a[0].first||j!=a[0].second)
		if (::a[i][j]!='X')
		{
			print(a[0].first,' ');
			print(a[0].second,' ');
			print(i,' ');
			print(j);
			return;
		}
	}
	for (int i=0;i<(int)A.size();i++)
	for (int j=0;j<i;j++)
	if ((int)(A[i]|A[j]).count()==cnt)
	{
		print(a[i].first,' ');
		print(a[i].second,' ');
		print(a[j].first,' ');
		print(a[j].second);
		return;
	}
	puts("-1");
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),m=read(),d=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]=='R') pos[id[i][j]=min(++cnt,M-1)]=make_pair(i,j);
	if (cnt>290) return puts("-1"),0;
	for (int i=1;i<=cnt;i++) bfs(pos[i].first,pos[i].second,i);
	for (int i=1;i<=cnt;i++) sort(who[i].begin(),who[i].end());
	for (int i=1;i<=cnt;i++)
	for (int j=i+1;j<=cnt;j++)
	if (check(who[i],who[j]))
	return solve(who[i],who[j]),0;
	vector<pair<int,int>>tmp;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (!h[i][j].empty())
	tmp.push_back(make_pair(i,j));
	solve(tmp);
	
	return 0;
}