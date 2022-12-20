#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > edges;
bool used[2000];
bool allowed[2000];
int val[2000];
int index[2000];

bool cmp(int a,int b)
{
	return val[a]<val[b];
}

long long dfs(int i)
{
	used[i] = 1;
	long long ways = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!used[edges[i][j]])
			if(allowed[edges[i][j]])
			{
				ways *= 1+dfs(edges[i][j]);
				ways %= 1000000007;
			}
	}
	return ways;
}

int main()
{
	int D,N;
	cin >> D >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		cin >> val[i];
	}
	for(int i=0;i<(N-1);i++)
	{
		int a,b;
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if((val[j]==val[i])&&(j>=i))
				allowed[j] = 1;
			else if((val[j]<val[i])&&((val[i]-val[j])<=D))
				allowed[j] = 1;
			else
				allowed[j] = 0;
			used[j] = 0;
		}
		ans += dfs(i);
		ans %= 1000000007;
	}
	cout << ans << endl;
}