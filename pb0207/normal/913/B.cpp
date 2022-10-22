#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

int n,deg[N];

vector<int>e[100001]; 

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		e[x].push_back(i);
		e[i].push_back(x);
		deg[x]++,deg[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)
			continue;
		int tot=0;
		for(int j=0;j<e[i].size();j++)
			if(deg[e[i][j]]==1)
				tot++;
		if(tot<3)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}