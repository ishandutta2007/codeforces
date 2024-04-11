#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define forl(v) for(int l=0; l<v; l++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define lli long long int
#define ss second
#define vvi vector<vector<int> > 
int main()
{
	vector<int> qow;
	int n,k;
	cin>>n>>k;
	int levels[n];
	int kessay[n];
	fori(n)
	{
		levels[i] = 0;
	}
	fori(k)
	{
		int eded;
		cin>>eded;
		--eded;
		levels[eded] = 1;
		qow.push_back(eded);
	}
	vector<vector<int> > g;
	vector<vector<int> > g_r;
	g.resize(n);
	g_r.resize(n);
	fori(n)
	{
		cin>>kessay[i];
		forj(kessay[i])
		{
			int eded;
			cin>>eded;
			--eded;
			g[i].push_back(eded);
			g_r[eded].push_back(i);
		}
	}
	int say = 0;
	int say2 = 0;
	vector<int> qow2;
	for(say; say<qow.size(); say++)
	{
		int hardan = qow[say];
		if(!kessay[hardan])
		{
			qow2.push_back(hardan);
		}
		forj(g[hardan].size())
		{
			int hara = g[hardan][j];
			if(!levels[hara])
			{
				levels[hara] = 1;
				qow.push_back(hara);
			}
		}
	}
	vector<int> sira;
	for(say2; say2<qow2.size(); say2++)
	{
		int hardan = qow2[say2];
		sira.push_back(hardan);
		forj(g_r[hardan].size())
		{
			int hara = g_r[hardan][j];
			--kessay[hara];
			if(levels[hara] && !kessay[hara])
			{
				qow2.push_back(hara);
			}
		}
	}
	if(say==say2)
	{
		cout<<say2<<endl;
		fori(sira.size())
		{
			cout<<sira[i]+1<<" ";
		}
	}
	else
	cout<<-1;
}