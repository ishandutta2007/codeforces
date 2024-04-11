#include <iostream>
#include <vector>
using namespace std;
#define fori(v) for(int i =0 ; i<v; i++)
#define forj(v) for(int j = 0 ; j<v; j++)

int main()
{
	int n, m , k;
	cin>>n>>m>>k;
	vector<vector<int> > g;
	g.resize(n);
	int olubmu[n];
	fori(n)
		olubmu[i] = 0;
	vector<int> ks;
	ks.resize(k);
	fori(k)
	{
		int eded;
		 cin>>eded;
		  --eded; 
		  ks[i] = eded;
	}
	fori(m)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int max = 0;
	int cem = 0;
	fori(k)
	{
		int hansi = ks[i];
		int node_say = 1;
		vector<int> qow;
		qow.push_back(hansi);
		olubmu[hansi] = 1;
		int z = 0;
		while(z<qow.size())
		{
			int hardan = qow[z];
			forj(g[hardan].size())
			{
				int hara = g[hardan][j];
				if(!olubmu[hara])
				{
					olubmu[hara] = 1;
					++node_say;
					qow.push_back(hara);
				}
			}
			++z;
		}
		int elave = node_say*(node_say-1)/2;
		if(node_say>max)
		max = node_say;
		cem+=elave;
	}
	cem-=m;
	int say = 0 ;
	fori(n)
	{
		if(!olubmu[i])
		++say;
	}
	cem+=max*say;
	cem+=say*(say-1)/2;
	cout<<cem;
	return 0;
}