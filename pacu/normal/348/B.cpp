#include <iostream>
#include <vector>
using namespace std;
#define INF (1000000000000000L)

long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	return (a*b)/gcd(a,b);
}

vector<vector<int> > edges;
int A[100000];
long long mul[100000];
bool used[100000];
long long weight[100000];

void dfs(int i)
{
	used[i] = 1;
	mul[i] = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!used[edges[i][j]])
		{
			dfs(edges[i][j]);
			if(mul[i] != INF)
				mul[i] = lcm(mul[i],mul[edges[i][j]]);
			if(mul[i] > 10e13)
				mul[i] = INF;
		}
	}
	if(mul[i] != INF)
		if(edges[i].size() > 1)
			mul[i] *= edges[i].size()-(i!=0);
	if(mul[i] > 10e13)
		mul[i] = INF;
	used[i] = 0;
}

long long ans;

long long dfs2(int i)
{
	long long low = INF;
	used[i] = 1;
	weight[i] = A[i];
	for(int j=0;j<edges[i].size();j++)
		if(!used[edges[i][j]])
		{
			long long cur = dfs2(edges[i][j]);
			low = min(low,cur);
			weight[i] += cur;
		}
	if(low < INF)
	{
		low *= ((long long)edges[i].size()-(i!=0));
		if(low < weight[i])
		{
			ans += weight[i] - low;
			weight[i] = low;
		}
	}
	ans += weight[i]%mul[i];
	weight[i] -= weight[i]%mul[i];
	used[i] = 0;
	return weight[i];
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		edges.push_back(vector<int>());
		used[i] = 0;
	}
	for(int i=1;i<N;i++)
	{
		int a,b;
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	ans = 0;
	dfs(0);
	dfs2(0);
	cout << ans << endl;
}