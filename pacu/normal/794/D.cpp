#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define B 314159
#define MOD1 1000000009
#define MOD2 1000000007

int N,M;
vector<int> edges[300000];
int h1[300000];
int h2[300000];
int cid[300000];

bool cmp(int a,int b)
{
	if(h1[a]==h1[b]) return h2[a]<h2[b];
	return h1[a]<h1[b];
}

int fid[300000];

void init()
{
	for(int i=0;i<N;i++)
		fid[i] = i;
}

int find(int i)
{
	if(fid[i]==i) return i;
	return fid[i] = find(fid[i]);
}

void join(int i,int j)
{
	i = find(i), j = find(j);
	fid[i] = j;
}

set<pair<int,int> > S;

vector<int> cedges[300000];

int ans[300000];
bool vis[300000];

void dfs(int i,int x)
{
	ans[i] = x;
	vis[i] = 1;
	if(cedges[i].size()>0 && !vis[cedges[i][0]]) dfs(cedges[i][0],x+1);
	if(cedges[i].size()>1 && !vis[cedges[i][1]]) dfs(cedges[i][1],x+1);
}

int main()
{
	scanf("%d %d",&N,&M);
	int a,b;
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=0;i<N;i++)
	{
		edges[i].push_back(i);
		sort(edges[i].begin(),edges[i].end());
		for(int j=0;j<edges[i].size();j++)
		{
			h1[i] = (B*((long long)h1[i]) + edges[i][j] + 1)%MOD1;
			h2[i] = (B*((long long)h2[i]) + edges[i][j] + 1)%MOD2;
		}
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	init();
	for(int i=1;i<N;i++)
	{
		if(!cmp(cid[i-1],cid[i]))
		{
			join(cid[i-1],cid[i]);
		}
	}
	int C = 0;
	for(int i=0;i<N;i++) if(find(i)==i)
	{
		C++;
		for(int j=0;j<edges[i].size();j++) if(find(edges[i][j])!=i)
		{
			if(S.find(make_pair(i,find(edges[i][j]))) == S.end())
			{
				cedges[i].push_back(find(edges[i][j]));
				S.insert(make_pair(i,find(edges[i][j])));
			}
		}
	}
	if(S.size() != 2*(C-1))
	{
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<N;i++) if(cedges[i].size()>2)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<N;i++)
		if(cedges[i].size()==1)
		{
			dfs(i,1);
			break;
		}
	if(C==1) ans[find(0)] = 1;
	printf("YES\n");
	for(int i=0;i<N;i++)
		printf("%d ",ans[find(i)]);
	printf("\n");
}