#include <iostream>
#include <algorithm>
using namespace std;

long long K;
int N,M;
int A[1000][1000];

int cid[1000000],sz[1000000];
void init()
{
	for(int i=0;i<N*M;i++)
		cid[i] = i, sz[i] = 1;
}
int find(int i)
{
	if(cid[i]==i) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return;
	if(sz[i] <= sz[j])
	{
		cid[i] = j;
		sz[j] += sz[i];
	}
	else
	{
		cid[j] = i;
		sz[i] += sz[j];
	}
}

bool vis[1000][1000];
int aid[1000000];

bool cmp(int a,int b)
{
	return A[a/M][a%M] > A[b/M][b%M];
}

int req;
bool seen[1000][1000];
int ans[1000][1000];

void dfs(int x,int y,int val)
{
	if(x<0 || y<0 || x>=N || y>=M) return;
	if(seen[x][y]) return;
	if(A[x][y] < val) return;
	if(req==0) return;
	seen[x][y] = 1;
	ans[x][y] = val;
	req--;
	dfs(x-1,y,val);
	dfs(x,y-1,val);
	dfs(x+1,y,val);
	dfs(x,y+1,val);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> A[i][j];
	init();
	for(int i=0;i<N*M;i++)
		aid[i] = i;
	sort(aid,aid+N*M,cmp);
	for(int i=0;i<N*M;i++)
	{
		int x = aid[i]/M;
		int y = aid[i]%M;
		vis[x][y] = 1;
		if(x>0 && vis[x-1][y]) join(M*(x-1)+y,M*x+y);
		if(y>0 && vis[x][y-1]) join(M*x+y-1,M*x+y);
		if(x<N-1 && vis[x+1][y]) join(M*(x+1)+y,M*x+y);
		if(y<M-1 && vis[x][y+1]) join(M*x+y,M*x+y+1);
		if(((K%A[x][y])==0) && (sz[find(M*x+y)] >= K/A[x][y]))
		{
			req = K/A[x][y];
			dfs(x,y,A[x][y]);
			cout << "YES\n";
			for(int a=0;a<N;a++)
			{
				for(int b=0;b<M;b++)
					cout << ans[a][b] << ' ';
				cout << '\n';
			}
			return 0;
		}
	}
	cout << "NO\n";
}