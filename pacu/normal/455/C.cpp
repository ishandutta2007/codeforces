#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > aEdges;
vector<int> aUsed;
vector<int> procRegion;

int deepestNode;
int maxDepth;


int id[300000];
int sz[300000];

void init()
{
	for(int i=0;i<300000;i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int i)
{
	int j = i;
	while(j!=id[j])
		j = id[j];
	id[i] = j;
	return j;
}

vector<int> maxLen;

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj)
		return;
	int maxi = maxLen[ri]/2;
	if((2*maxi)<maxLen[ri])
		maxi++;
	int maxj = maxLen[rj]/2;
	if((2*maxj)<maxLen[rj])
		maxj++;
	if(sz[ri]>sz[rj])
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
		maxLen[ri] = max(1+maxi+maxj,max(maxLen[ri],maxLen[rj]));
	}
	else
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
		maxLen[rj] = max(1+maxi+maxj,max(maxLen[ri],maxLen[rj]));
	}
	
}

void ljoin(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj)
		return;
	if(sz[ri]>sz[rj])
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
	}
	else
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
	}
}

void dfs(int i,int depth,int cRegion)
{
	if(aUsed[i]) return;
	aUsed[i] = 1;
	procRegion[i] = cRegion;
	if(depth>maxDepth)
	{
		maxDepth = depth;
		deepestNode = i;
	}
	for(int j=0;j<aEdges[i].size();j++)
		dfs(aEdges[i][j],depth+1,cRegion);
	aUsed[i] = 0;
}



int main()
{
	int N,M,Q;
	int i,j,a,b;
	cin >> N >> M >> Q;
	init();
	for(i=0;i<N;i++)
	{
		aEdges.push_back(vector<int>());
		procRegion.push_back(0);
		aUsed.push_back(0);
		maxLen.push_back(0);
	}
	for(i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		aEdges[a].push_back(b);
		aEdges[b].push_back(a);
	}
	int curRegion = 0;
	for(i=0;i<N;i++)
	{
		if(procRegion[i])
			continue;
		curRegion++;
		maxDepth = -1;
		dfs(i,0,i+1);
		maxDepth = -1;
		dfs(deepestNode,0,i+1);
		maxLen[i] = maxDepth;
	}
	for(i=0;i<N;i++)
	{
		procRegion[i]--;
		ljoin(i,procRegion[i]);
	}
	int tp,x,y;
	for(i=0;i<Q;i++)
	{
		cin >> tp >> x;
		if(tp==1)
			printf("%d\n",maxLen[find(x-1)]);
		else
		{
			cin >> y;
			x--,y--;
			join(x,y);
		}
	}
}