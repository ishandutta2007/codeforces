#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int ee[200000];
long long tm[200000];
vector<vector<int> > edges;

bool used[100000];
long long depth[100000];
long long surfaceTime[100000];

void dfs(int i,long long d)
{
	used[i] = 1;
	depth[i] = d;
	for(int j=0;j<edges[i].size();j++)
		if(!used[ee[edges[i][j]]])
			dfs(ee[edges[i][j]],d+tm[edges[i][j]]);
	used[i] = 0;
}

void dfsTime(int i,long long d)
{
	used[i] = 1;
	surfaceTime[i] = max(surfaceTime[i],d);
	for(int j=0;j<edges[i].size();j++)
		if(!used[ee[edges[i][j]]])
			dfsTime(ee[edges[i][j]],d+tm[edges[i][j]]);
	used[i] = 0;
}

int sortedID[100000];

bool cmpID(int a,int b)
{
	return surfaceTime[a]>surfaceTime[b];
}

int id[100000];
int sz[100000];
int vCount[100000];

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		id[i] = i;
		sz[i] = vCount[i] = 1;
	}
}

int find(int i)
{
	int j = id[i];
	while(id[j] != j)
		j = id[j];
	id[i] = j;
	return j;
}

int join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri == rj) return vCount[ri];
	if(sz[ri] < sz[rj]) swap(ri,rj);
	id[rj] = ri;
	sz[ri] += sz[rj];
	vCount[ri] += vCount[rj];
	return vCount[ri];
}

void remove(int i)
{
	vCount[find(i)]--;
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		used[i] = 0;
		surfaceTime[i] = 0;
	}
	int a,b,t;
	for(int i=0;i<(N-1);i++)
	{
		cin >> a >> b >> t;
		a--,b--;
		ee[2*i] = b;
		tm[2*i] = t;
		edges[a].push_back(2*i);
		ee[2*i+1] = a;
		tm[2*i+1] = t;
		edges[b].push_back(2*i+1);
	}
	dfs(0,0);
	int s1 = 0;
	for(int i=1;i<N;i++)
		if(depth[i]>depth[s1])
			s1 = i;
	dfs(s1,0);
	int s2 = 0;
	for(int i=1;i<N;i++)
		if(depth[i]>depth[s2])
			s2 = i;
	dfsTime(s1,0);
	dfsTime(s2,0);

//	for(int i=0;i<N;i++)
//		cout << surfaceTime[i] << " ";
//	cout << endl;

	for(int i=0;i<N;i++)
		sortedID[i] = i;
	sort(sortedID,sortedID+N,cmpID);
	
	int Q;
	long long l;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> l;
		int back = 0;
		int best = 0;
		init(N);
		for(int i=0;i<N;i++)
		{
			int cur = sortedID[i];
			while((surfaceTime[sortedID[back]]-surfaceTime[cur])>l)
			{
//				cout << cur+1 << " " << sortedID[back]+1 << endl;
				remove(sortedID[back]);
				back++;
			}
			for(int j=0;j<edges[cur].size();j++)
				if(surfaceTime[ee[edges[cur][j]]]>=surfaceTime[cur])
					best = max(best,join(cur,ee[edges[cur][j]]));
		}
		cout << best << endl;
	}
	return 0;
}