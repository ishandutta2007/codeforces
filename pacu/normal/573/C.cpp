#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[100000];
bool vis[100000];

int num2;
bool toobig;
int bigvertex;

void dfs(int i,bool &isPath,int &ecount)
{
	vis[i] = 1;
	int np = 0;
	ecount = edges[i].size();
	if(i != bigvertex) ecount--;
	bool p;
	int e;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[edges[i][j]])
		{
			dfs(edges[i][j],p,e);
			if(!p) np++;
			ecount = max((int)edges[edges[i][j]].size(),max(ecount,e));
			//ecount = max(ecount,e);
		}
	}
	isPath = ecount<=2;
	if(np > 2) toobig = 1;
	if(np == 2) num2++,bigvertex = i;
}

int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int a,b;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bool p;
	int e;
	bigvertex = 0;
	toobig = num2 = 0;
	dfs(0,p,e);
	if(toobig || num2>1)
	{
		cout << "No\n";
		return 0;
	}
	for(int i=0;i<N;i++)
		vis[i] = 0;
	toobig = num2 = 0;
	dfs(bigvertex,p,e);
	if(toobig || num2>1)
	{
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	return 0;
}