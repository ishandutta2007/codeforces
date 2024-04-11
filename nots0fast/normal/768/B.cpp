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
#define lli long long int
#define ss second
vector<lli> hamisi;
lli log2( lli n)
{
	lli say =-1;
	while(n>0)
	{
		hamisi.push_back(n%2);
		n/=2;
		++say;
	}
	reverse(hamisi.begin(),hamisi.end());
	return say;
}
lli bit_by_bit (lli l,lli n)
{
	if(l>pow(2,n))
	{
		l-=pow(2,n);
		return bit_by_bit(l,n);
	}
	else if(l<pow(2,n))
	{
		return bit_by_bit(l,n-1);
	}
	else
	{
		return hamisi[n];
	}
}
int main()
{
	lli n,l,r;
	cin>>n>>l>>r;
	lli cemi = 0;
	lli loqa = 0;
	if(n!=0)
	loqa = log2(n);
	else
	hamisi.push_back(0);
	for(l ; l<r+1; l++)
	{
		cemi+=bit_by_bit(l,loqa);
	}
	cout<<cemi;
}