#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
vector<int> g[30],topo;
string s[maxn];
int n;
bool vis[30],use[30];
void dfs(int x)
{
	vis[x]=use[x]=true;
	for(int i=0;i<g[x].size();i++)
		if(use[g[x][i]])
		{
			puts("Impossible");
			exit(0);
		}
		else if(!vis[g[x][i]])
			dfs(g[x][i]);
	use[x]=false;
	topo.push_back(x);
}
void func(int id)
{
	for(int i=0;i<s[id].size()&&i<s[id+1].size();i++)
		if(s[id][i]!=s[id+1][i])
		{
			g[s[id+1][i]-'a'].push_back(s[id][i]-'a');
			return ;
		}
	if(s[id].size()>s[id+1].size())
	{
		puts("Impossible");
		exit(0);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<n;i++)
		func(i);
	for(int i=0;i<26;i++)
		if(!vis[i])
			dfs(i);
	for(int i=0;i<26;i++)
		putchar(topo[i]+'a');
	return 0;
}