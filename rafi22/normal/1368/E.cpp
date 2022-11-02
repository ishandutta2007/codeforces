#include <bits/stdc++.h>
using namespace std;

int ile[200007];
int path[200007];
vector <int> G[200007];
vector <int> G1[200007];
deque <int> kolejka;
vector <int> res;

void clean(int n)
{
	for(int i=0;i<=n;i++)
	{
		ile[i]=0;
		path[i]=0;
		G[i].clear();
		G1[i].clear();
	}
	res.clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,m,a,b;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			G[a].push_back(b);
			G1[b].push_back(a);
			ile[b]++;
		}
	
	for(int i=1;i<=n;i++) 
	{
		if(ile[i]==0)
		{
			kolejka.push_back(i);
		}
	}
	while(!kolejka.empty())
	{
		int p=kolejka[0],maxi=-1;
		
		for(int i=0;i<G1[p].size();i++)
		{
			maxi=max(maxi,path[G1[p][i]]);
		}
		
		path[p]=maxi+1;
		if(path[p]>=2)
		{
			res.push_back(p);
			path[p]=-1;
		}
		for(int i=0;i<G[p].size();i++)
		{
			ile[G[p][i]]--;
			if(ile[G[p][i]]==0) kolejka.push_back(G[p][i]);
		}
		kolejka.pop_front();
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;
	clean(n);
	}
	return 0;
}