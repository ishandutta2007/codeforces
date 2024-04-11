#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
int out[400000];
int from[400000];
int ednum[400000];
long long ans[400000];
vector<vector<int> > edges;
vector<vector<long long> > l,r;
bool vis[200000];

long long det(int e)
{
	if(ans[e] != -1) return ans[e];
	ans[e] = 1;
	int v = out[e];
	while(l[v].size() < ednum[e^1]+1)
		l[v].push_back((l[v].back()*det(edges[v][l[v].size()-1]))%MOD);
	while(r[v].size() < (edges[v].size()-ednum[e^1]))
		r[v].push_back((r[v].back()*det(edges[v][edges[v].size()-r[v].size()]))%MOD);
	ans[e] = (l[v][ednum[e^1]]*r[v][edges[v].size()-ednum[e^1]-1]+1)%MOD;
	return ans[e];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		l.push_back(vector<long long>());
		r.push_back(vector<long long>());
		l[i].push_back(1);
		r[i].push_back(1);
	}
	for(int i=1;i<N;i++)
	{
		cin >> b;
		b--;
		ednum[2*i] = edges[i].size();
		ednum[2*i+1] = edges[b].size();
		edges[i].push_back(2*i);
		edges[b].push_back(2*i+1);
		out[2*i] = b;
		out[2*i+1] = i;
		from[2*i] = i;
		from[2*i+1] = b;
		ans[2*i] = ans[2*i+1] = -1;
	}
	for(int i=0;i<N;i++)
	{
		int p = 1;
		for(int j=0;j<edges[i].size();j++)
			p = (p*det(edges[i][j]))%MOD;
		cout << p << " ";
	}
	cout << '\n';
}