#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> edges[100000];
int par[100000];
int c[100000];

map<int,int> M[100000];
long long sm[100000];
int mfreq[100000];
int alloc;
long long ans[100000];

void insert(int i,int col,int occ)
{
	M[i][col] += occ;
	if(M[i][col] == mfreq[i])
		sm[i] += col;
	else if(M[i][col] > mfreq[i])
		sm[i] = col, mfreq[i] = M[i][col];
}

int dfs(int v,int par)
{
//	cout << "Entered " << v << '\n';
	int i = -1;
	for(int j=0;j<edges[v].size();j++)
	{
//		cout << "About to Check " << edges[v][j] << "; " << i << '\n';
		if(edges[v][j]!=par)
		{
			if(i==-1) i = dfs(edges[v][j],v);
			else
			{
//				cout << "Reached " << edges[v][j] << '\n';
				int k = dfs(edges[v][j],v);
				if(M[i].size() < M[k].size())
					swap(i,k);
				for(map<int,int>::iterator it=M[k].begin();it!=M[k].end();it++)
					insert(i,it->first,it->second);
			}
		}
	}
	if(i==-1)
		i = alloc++;
	insert(i,c[v],1);
	ans[v] = sm[i];
//	cout << "Exited " << v << '\n';
	return i;
}

int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> c[i];
	int a,b;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	for(int i=0;i<N;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}