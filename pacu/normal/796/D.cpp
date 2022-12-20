#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,K,D;
vector<int> edges[300000];
int pol[300000];
bool ispol[300000];
int npol[300000];
int d[300000];

int que[300000];

int ea[300000];
int eb[300000];

void bfs()
{
	for(int i=0;i<N;i++)
		d[i] = -1;
	for(int i=0;i<K;i++)
	{
		npol[pol[i]] = pol[i];
		d[pol[i]] = 0;
		que[i] = pol[i];
	}
	int len = K;
	int cur = 0;
	while(cur<len)
	{
		int x = que[cur++];
		if(d[x]==D) continue;
		for(int j=0;j<edges[x].size();j++)
		{
			if(d[edges[x][j]]==-1)
			{
				que[len++] = edges[x][j];
				npol[edges[x][j]] = npol[x];
				d[edges[x][j]] = d[x]+1;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K >> D;
	int p;
	for(int i=0;i<K;i++)
	{
		cin >> p;
		p--;
		ispol[p] = 1;
	}
	K = 0;
	for(int i=0;i<N;i++)
		if(ispol[i])
			pol[K++] = i;
	int a,b;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		ea[i] = a, eb[i] = b;
	}
	bfs();
	cout << K-1 << '\n';
	for(int i=0;i<N-1;i++)
		if(npol[ea[i]] != npol[eb[i]])
			cout << i+1 << ' ';
	cout << '\n';
	return 0;
}