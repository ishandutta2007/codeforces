#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define lli long long int
int main()
{
	int n , m;
	cin>>n>>m;
	vector<vector<int> > hamisi;
	hamisi.resize(n);
	int olubmu[n];
	fori(n)
	{
		olubmu[i] = 0;
	}
	fori(m)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		hamisi[a].push_back(b);
		hamisi[b].push_back(a);
	}
	fori(n)
	{
		if(!olubmu[i] )
		{
			set<int> olanlar;
			int say =0;
			olubmu[i] = 1;
			forj(hamisi[i].size())
			{
				olanlar.insert(hamisi[i][j]);
				olubmu[hamisi[i][j]]=1;
			}
			olanlar.insert(i);
			forj(hamisi[i].size())
			{
				int hardan = hamisi[i][j];
				int say = olanlar.size();
				fork(hamisi[hardan].size())
				{
					int hara = hamisi[hardan][k];
					if(olanlar.find(hara)!=olanlar.end())
					{
						--say;
					}
					else
					{
						cout<<"NO";
						return 0;
					}
				}
				if(say!=1)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
}