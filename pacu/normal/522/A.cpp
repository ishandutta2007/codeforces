#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > edges;
map<string,int> M;
bool used[500];

int dfs(int i,int d)
{
	int mx = d;
	used[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(!used[edges[i][j]])
			mx = max(mx,dfs(edges[i][j],d+1));
	return mx;
}

int main()
{
	int N;
	string s;
	int a,b;
	cin >> N;
	int cur = 0;
	for(int i=0;i<=N;i++)
		edges.push_back(vector<int>());
	for(int i=0;i<N;i++)
	{
		cin >> s;
		for(int c=0;c<s.size();c++)
			if(s[c]<97) s[c] += 32;
		if(M.find(s) != M.end())
			a = M[s];
		else
		{
			a = cur++;
			M[s] = a;
		}
		cin >> s;
		cin >> s;
		for(int c=0;c<s.size();c++)
			if(s[c]<97) s[c] += 32;
		if(M.find(s) != M.end())
			b = M[s];
		else
		{
			b = cur++;
			M[s] = b;
		}
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	cout << dfs(1,1) << endl;
	return 0;
}