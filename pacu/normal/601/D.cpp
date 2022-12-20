#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
	char c;
	node *ch[26];
	int sz;
	node()
	{
		for(int i=0;i<26;i++)
			ch[i] = NULL;
		sz = 1;
	}
};

void merge(node *a,node *b)
{
//	cout << "Entered Merge\n";
	a->sz = 1;
	for(int i=0;i<26;i++)
	{
		if(a->ch[i]!=NULL && b->ch[i]!=NULL)
		{
			merge(a->ch[i],b->ch[i]);
			a->sz += a->ch[i]->sz;
		}
		else if(b->ch[i]!=NULL)
		{
			a->ch[i] = b->ch[i];
			a->sz += a->ch[i]->sz;
		}
		else if(a->ch[i]!=NULL)
			a->sz += a->ch[i]->sz;
	}
}

vector<int> edges[300000];
int N;
int cv[300000],ans[300000];
char s[300001];

node *dfs(int i,int par)
{
//	cout << "Entered " << i << '\n';
	node *cur = new node;
	cur->c = s[i];
	cur->sz = 1;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j] != par)
		{
			if(cur->ch[s[edges[i][j]]-'a'] == NULL)
				cur->ch[s[edges[i][j]]-'a'] = dfs(edges[i][j],i);
			else
				merge(cur->ch[s[edges[i][j]]-'a'],dfs(edges[i][j],i));
		}
//	cout << cur->sz << '\n';
	for(int j=0;j<26;j++)
		if(cur->ch[j] != NULL)
		{
			cur->sz += cur->ch[j]->sz;
//			cout << "Adding " << cur->ch[j]->sz << '\n';
		}
	ans[i] = cv[i]+cur->sz;
	return cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> cv[i];
	cin >> s;
	int a,b;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	int topval = -1;
	int numval;
	for(int i=0;i<N;i++)
	{
		if(ans[i]==topval) numval++;
		else if(ans[i]>topval)
		{
			topval = ans[i];
			numval = 1;
		}
	}
	cout << topval << '\n' << numval << '\n';
}