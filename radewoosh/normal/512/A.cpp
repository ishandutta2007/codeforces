#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <char> graf[500];
string tab[107];
vector <char> post;
int bylo[1007];
int num[1007];
int czy;

void dfs(char v)
{
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (!bylo[graf[v][i]])
		{
			dfs(graf[v][i]);
		}
	}
	post.push_back(v);
	num[v]=post.size();
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> tab[i];
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			czy=1;
			for (int l=0; l<min(tab[i].size(), tab[j].size()); l++)
			{
				if (tab[i][l]!=tab[j][l])
				{
					graf[tab[i][l]].push_back(tab[j][l]);
					czy=0;
					break;
				}
			}
			if (czy && tab[i].size()>tab[j].size())
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	for (char i='a'; i<='z'; i++)
	{
		if (!bylo[i])
		dfs(i);
	}
	for (char i='a'; i<='z'; i++)
	{
		for (int j=0; j<graf[i].size(); j++)
		{
			if (num[i]<num[graf[i][j]])
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	while(!post.empty())
	{
		printf("%c", post.back());
		post.pop_back();
	}
	return 0;
}