#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int v0,v1,w0,w1;

int par[5000];
vector<int> edges[5000];
int sz[5000];
bool isAnc[5000];

int sm[2];
vector<int> flip[2];

void getFlippers(int v,int iSum,int fac)
{
	isAnc[v] = 1;
	while(par[v] != 0)
	{
		int p = par[v];
		isAnc[p] = 1;
		for(int j=0;j<edges[p].size();j++)
			if(edges[p][j]!=v)
			{
				sm[iSum] += fac*sz[edges[p][j]];
				flip[iSum^1].push_back(sz[edges[p][j]]);
			}
		v = p;
	}
}

bool pos[5001];

int main()
{
	cin >> N >> v0 >> v1 >> w0 >> w1;
	v0--,v1--,w0--,w1--;
	for(int i=1;i<N;i++)
	{
		cin >> par[i];
		par[i]--;
		edges[par[i]].push_back(i);
	}
	for(int i=0;i<N;i++)
		if(edges[i].size()==0)
			sz[i] = 1;
	for(int i=N-1;i>0;i--)
		sz[par[i]] += sz[i];
	getFlippers(v0,0,1);
	getFlippers(w0,1,1);
	getFlippers(v1,0,-1);
	getFlippers(w1,1,-1);
	for(int j=0;j<edges[0].size();j++)
		if(!isAnc[edges[0][j]])
		{
			flip[0].push_back(sz[edges[0][j]]);
			flip[1].push_back(sz[edges[0][j]]);
		}
	for(int k=0;k<2;k++)
	{
		int tot = sm[k];
		for(int j=0;j<flip[k].size();j++)
			tot += flip[k][j];
		if(tot%2 || tot<0)
		{
			cout << "NO\n";
			return 0;
		}
		tot /= 2;
		for(int i=0;i<=tot;i++)
			pos[i] = 0;
		pos[0] = 1;
		for(int j=0;j<flip[k].size();j++)
			for(int i=tot-flip[k][j];i>=0;i--)
				if(pos[i])
					pos[i+flip[k][j]] = 1;
		if(!pos[tot])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}