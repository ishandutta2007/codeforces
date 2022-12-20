#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edges;
int depth[200000];
bool vis[200000];
int needHigh[200000];
int needLow[200000];
int leaves;

void dfs(int i,int d)
{
	vis[i] = 1;
	depth[i] = d;
	if((i==0)&&(edges[i].size()==0))
	{
		needHigh[i] = needLow[i] = 1;
		leaves++;
	}
	else if((i>0)&&(edges[i].size() == 1))
	{
		needHigh[i] = needLow[i] = 1;
		leaves++;
	}
	else if(!(depth[i]%2)) // max
	{
		needHigh[i] = 500000;
		needLow[i] = 0;
	}
	else
	{
		needHigh[i] = 0;
		needLow[i] = 500000;
	}
	for(int j=0;j<edges[i].size();j++)
		if(!vis[edges[i][j]])
		{
			dfs(edges[i][j],d+1);
			if(!(depth[i]%2))
			{
				needHigh[i] = min(needHigh[i],needHigh[edges[i][j]]);
				needLow[i] += needLow[edges[i][j]];
			}
			else
			{
				needLow[i] = min(needLow[i],needLow[edges[i][j]]);
				needHigh[i] += needHigh[edges[i][j]];
			}
		}
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		vis[i] = 0;
	}
	int a,b;
	for(int i=0;i<(N-1);i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	leaves = 0;
	dfs(0,0);
	if(N==1)
		cout << "1 1\n";
	else
		cout << leaves+1-needHigh[0] << " " << needLow[0] << endl;
	return 0;
}