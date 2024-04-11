#include <iostream>
#include <string>
#include <math.h>
#include <vector>
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
#define ss second
int main()
{
	int n;
	cin>>n;
	vector<int> hamisi;
	hamisi.resize(n);
	int minn =2*pow(10,9) , maxx= -2*pow(10,9); 
	fori(n)
	{
		cin>>hamisi[i];
		if(hamisi[i]>maxx)
		{
			maxx = hamisi[i];
		}
		if(hamisi[i]<minn)
		{
			minn = hamisi[i];
		}
	}
	int say = 0;
	fori(n)
	{
		if(hamisi[i]!=minn && hamisi[i]!=maxx)
		{
			++say;
		}
	}
	cout<<say;
}