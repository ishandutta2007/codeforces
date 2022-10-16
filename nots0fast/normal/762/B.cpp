#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define lli long long int
bool John (pair<int,string> a, pair<int,string> b)
{
	return a.ff < b.ff;
}
int main()
{
	int usb, ps, both;
	cin>>usb>>ps>>both;
	vector<pair<int,string> > hamisi;
	int m;
	cin>>m;
	hamisi.resize(m);
	fori(m)
	{
		cin>>hamisi[i].ff>>hamisi[i].ss;
	}
	sort(hamisi.begin(), hamisi.end(), John);
	int say = 0;
	lli sum = 0;
	fori(m)
	{
		if(hamisi[i].ss[0]=='U')
		{
			if(usb || both)
			{
				sum+=hamisi[i].ff;
				++say;
				if(usb)
				--usb;
				else if(both)
				--both;
			}
		}
		else
		{
			if(ps || both)
			{
				sum+=hamisi[i].ff;
				++say;
				if(ps)
				--ps;
				else if(both)
				--both;
			}
		}
	}
	cout<<say<<" "<<sum;
}