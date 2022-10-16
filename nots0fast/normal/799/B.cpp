#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define lli long long int
int MAX = pow(10,2);
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-7;
int main()
{
	multimap<int,int> colors[4];
	int n;
	cin>>n;
	int costs[n];
	int fronts[n];
	int backs[n];
	fori(n)
	cin>>costs[i];
	fori(n)
	cin>>fronts[i];
	fori(n)
	cin>>backs[i];
	
	fori(n)
	{
		colors[fronts[i]].insert(mp(costs[i],backs[i]));
		colors[backs[i]].insert(mp(costs[i],fronts[i]));
	}
	int m;
	cin>>m;
	int cavablar[m];
	fori(m)
	{
		int c;
		cin>>c;
		multimap<int,int> :: iterator it = colors[c].begin();
		if(it==colors[c].end())
		cavablar[i] = -1;
		else
		{
			cavablar[i] = (*it).ff;
			int xardan = (*it).ss;
			colors[c].erase(it);
			 it = colors[xardan].find(cavablar[i]);
			 while((*it).ss!=c)
			 {
			 	++it;
			 }
			 colors[xardan].erase(it);
		}
	}
	fori(m)
	cout<<cavablar[i]<<" ";
}