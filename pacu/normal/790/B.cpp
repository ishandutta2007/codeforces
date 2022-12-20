#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,K;
vector<int> edges[200000];
int sz[200000];
int num[200000][5];
long long tot[5];
long long sm;

void dfs(int i,int par)
{
	sz[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
		{
			dfs(edges[i][j],i);
			sz[i] += sz[edges[i][j]];
			for(int a=0;a<K;a++)
				for(int b=0;b<K;b++)
					tot[(a+b+1)%K] += num[i][a]*((long long)num[edges[i][j]][b]);
			for(int b=0;b<K;b++)
				num[i][(b+1)%K] += num[edges[i][j]][b];
		}
	for(int a=0;a<K;a++)
		tot[a] += num[i][a];
	num[i][0]++;
	if(par!=-1)
		sm += sz[i]*((long long)(N-sz[i]));
}

int main()
{
	cin >> N >> K;
	int a,b;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	sm -= K*tot[0];
	for(int a=1;a<K;a++)
		sm -= a*tot[a];
	cout << sm/K + (N*((long long)(N-1)))/2 << '\n';
}