#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define forz(v) for(int z=0; z<v; z++)
#define mp(a,b) make_pair(a,b)
#define lli long long int
#define MAX 1001
int main()
{
	int n;
	cin>>n;
	int olubmu[n] = { };
	vector<vector<int> > g;
	g.resize(n);
	fori(n)
	{
		int a;
		cin>>a;
		--a;
		g[i].push_back(a);
		g[a].push_back(i);
	}
	int say = 0;
	fori(n)
	{
		if(!olubmu[i])
		{
			olubmu[i] = 1;
			vector<int> qow;
			qow.push_back(i);
			++say;
			forj(qow.size())
			{
				int hardan = qow[j];
				fork(g[hardan].size())
				{
					int hara = g[hardan][k];
					if(!olubmu[hara])
					{
						olubmu[hara] = 1;
						qow.push_back(hara);
					}
				}
			}
		}
	}
	cout<<say;
}