#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N,M,Q;
char A[200][200];
int comp[200][200];
bool cont[40000][10];
string s;
bool scont[1000001][10];
int vis[200][200];
int a[10],b[10];
bool hasIn[200][200];
bool incyc[200][200];
vector<pair<int,int> > edges[200][200];

void dfs(int i,int j,int c)
{
	if(vis[i][j] == 2)
		return;
	if(vis[i][j] == 1)
	{
		cont[c][A[i][j]-'0'] = 1, incyc[i][j] = 1, comp[i][j] = c;
	}
	vis[i][j]++;
	int c1 = i+ a[A[i][j]-'0'];
	int c2 = j + b[A[i][j]-'0'];
	if(c1>=0 && c1<N && c2>=0 && c2<M)
		dfs(c1,c2,c);
	else
		dfs(i,j,c);
}
int val[200][200];

bool dfs2(int i,int j)
{
	pair<int,int> e;
	vis[i][j] = 1;
	for(int k=0;k<edges[i][j].size();k++)
	{
		e = edges[i][j][k];
		if(!vis[e.first][e.second])
			if(dfs2(e.first,e.second))
				return 1;
		val[i][j] = max(val[i][j],val[e.first][e.second]+((A[i][j]==s[val[e.first][e.second]])?1:0));
	}
	if(incyc[i][j])
	{
		bool good = 1;
		for(int k=0;k<10;k++)
			if(scont[val[i][j]][k] && !cont[comp[i][j]][k])
				good = 0;
		if(good)
			return 1;	
	}
	if(val[i][j]==s.size())
		return 1;
	return 0;
}

bool bfs()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			vis[i][j] = 0, val[i][j] = (A[i][j]==s[0]);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!vis[i][j])
				if(dfs2(i,j))
					return 1;
	return 0;
}

int main()
{
	cin >> N >> M >> Q;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> A[i][j];
	for(int i=0;i<10;i++)
		cin >> a[i] >> b[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			int c1 = i+a[A[i][j]-'0'];
			int c2 = j+b[A[i][j]-'0'];
			if(c1 >=0 && c1<N && c2>=0 && c2<M)
			{
				hasIn[c1][c2] = 1;
				edges[c1][c2].push_back(make_pair(i,j));
			}
		}
	int c = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!hasIn[i][j])
				dfs(i,j,c++);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!vis[i][j])
			{
				dfs(i,j,c++);
			}
	for(int i=0;i<Q;i++)
	{
		cin >> s;
		for(int k=0;k<10;k++)
			scont[s.size()][k] = 0;
		for(int j=s.size()-1;j>=0;j--)
		{
			for(int k=0;k<10;k++)
				scont[j][k] = scont[j+1][k];
			scont[j][s[j]-'0'] = 1;
		}
		if(bfs()) cout << "YES\n";
		else cout << "NO\n";
	}
}