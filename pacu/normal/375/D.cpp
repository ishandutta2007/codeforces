#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
greater<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

map<int,int> M[100000];
ordered_set S[100000];
int C;

int color[100000];
int pnt[100000];
vector<int> edges[100000];
vector<int> queries[100000];
int k[100000],ans[100000];

void dfs(int i,int par)
{
	pnt[i] = -1;
	int nxt;
	for(int j=0;j<edges[i].size();j++)
	{
		if(edges[i][j] != par)
		{
			dfs(edges[i][j],i);
			if(pnt[i]==-1 || M[pnt[i]].size() < M[pnt[edges[i][j]]].size())
				pnt[i] = pnt[edges[i][j]];
		}
	}
	if(pnt[i] == -1)
		pnt[i] = C++;
	int e;
	for(int j=0;j<edges[i].size();j++)
	{
		e = edges[i][j];
		if(e != par)
		{
			if(pnt[i] != pnt[e])
			{
				for(map<int,int>::iterator it = M[pnt[e]].begin(); it != M[pnt[e]].end(); it++)
				{
					if(M[pnt[i]].find(it->first) != M[pnt[i]].end())
					{
						S[pnt[i]].erase(S[pnt[i]].find(make_pair(M[pnt[i]][it->first],it->first)));
					}
					M[pnt[i]][it->first] += it->second;
					S[pnt[i]].insert(make_pair(M[pnt[i]][it->first],it->first));
				}
			}
		}
	}
	/*
	cout << i << ": ";
	for(ordered_set::iterator it = S[pnt[i]].begin(); it != S[pnt[i]].end(); it++)
		cout << it->first << ' ' << it->second << "; ";
	cout << '\n';
	*/
	if(M[pnt[i]].find(color[i]) != M[pnt[i]].end())
		S[pnt[i]].erase(S[pnt[i]].find(make_pair(M[pnt[i]][color[i]],color[i])));
	M[pnt[i]][color[i]]++;
	S[pnt[i]].insert(make_pair(M[pnt[i]][color[i]],color[i]));
	for(int j=0;j<queries[i].size();j++)
		ans[queries[i][j]] = S[pnt[i]].order_of_key(make_pair(k[queries[i][j]]-1,1000000000));
}

int main()
{
	ios::sync_with_stdio(0);
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> color[i];
	int a,b;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int v,c;
	for(int i=0;i<Q;i++)
	{
		cin >> v >> c;
		v--;
		queries[v].push_back(i);
		k[i] = c;
	}
	dfs(0,-1);
	for(int i=0;i<Q;i++)
		cout << ans[i] << '\n';
}