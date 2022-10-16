#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define lli long long int
#define ss second
string to_binary(int eded)
{
	string bow = "";
	while(eded>0)
	{
		bow+=(eded%2)+'0';
		eded/=2;
	}
	reverse(bow.begin(),bow.end());
	return bow;
}
int to_decimal(string z)
{
	int cem =0;
	for(int i=0; i<z.length(); i++)
	{
		cem*=2;
		cem+=z[i]-'0';
	}
	return cem;
}
int main()
{
	vector<string> binar;
	int n,k,x;
	cin>>n>>k>>x;
	string esas = to_binary(x);
	vector<int> first;
	fori(n)
	{
		int eded;
		cin>>eded;
		first.push_back(eded);
	}
	sort(first.begin(),first.end());
	int mini ,maxi;
	k = min(k%4+4,k);
	forz(k)
	{	
	    vector<int> hamisi;
		fori(n)
		{
			string a = to_binary(first[i]);
			while(a.length()<esas.length())
			{
				a.insert(0,"0");
			}
			binar.push_back(a);
		}
		fori(binar.size())
		{
			if((i%2))
			{
				hamisi.push_back(to_decimal(binar[i]));
				continue;
			}
			string xansi = binar[i];
			forj(esas.length())
			{
				if(esas[esas.length()-j-1]!=xansi[xansi.length()-j-1])
				{
					xansi[xansi.length()-j-1] = '1';
				}
				else
				{
					xansi[xansi.length()-j-1] = '0';
				}
			}
			hamisi.push_back(to_decimal(xansi));
		}
		sort(hamisi.begin(),hamisi.end());
	/*	fori(hamisi.size())
		{
			cout<<hamisi[i]<<" ";
		}
		cout<<endl;*/
		binar.clear();
		first = hamisi;
    }
		mini = first[0];
		maxi = first[first.size()-1];
    cout<<maxi<<" "<<mini<<endl;
}