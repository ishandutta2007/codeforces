#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> edges[2000];

vector<int> redges[100000];
int comp[100000];
int vis[100000];
vector<int> L;
int C;

void dfsSCC(int i)
{
	vis[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(!vis[edges[i][j]])
			dfsSCC(edges[i][j]);
	L.push_back(i);
}

void dfsSCC2(int i,int c)
{
	comp[i] = c;
	for(int j=0;j<redges[i].size();j++)
		if(!comp[redges[i][j]])
			dfsSCC2(redges[i][j],c);
}

void scc()
{
	for(int i=0;i<N;i++) vis[i] = comp[i] = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<edges[i].size();j++)
			redges[edges[i][j]].push_back(i);
	L.clear();
	for(int i=0;i<N;i++)
		if(!vis[i])
			dfsSCC(i);
	reverse(L.begin(),L.end());
	for(int i=0;i<N;i++)
		if(!comp[L[i]])
			dfsSCC2(L[i],++C);
}

int main()
{
	scanf("%d",&N);
	int a;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&a);
			if(a) edges[i].push_back(j);
		}
	}
	scc();
	if(C==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}