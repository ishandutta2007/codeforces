#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
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
	lli n ;
	int k;
	cin>>n>>k;
	lli kok = sqrt(n);
	vector<lli> hamisi;
	for(int i=1; i<=kok; i++)
	{
		if(!(n%i))
		{
			hamisi.push_back(i);
			lli yeni = n/i;
			if(i!=kok || (kok*kok!=n))
			hamisi.push_back(yeni);
		}
	}
	sort(hamisi.begin(),hamisi.end());
	if(k>hamisi.size())
	{
		cout<<-1;
	}
	else
	{
		cout<<hamisi[k-1];
	}
}