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
	int n,m;
	cin>>n>>m;
	set<string> hamisi;
	fori(n)
	{
		string c;
		cin>>c;
		hamisi.insert(c);
	}
	int say = 0;
	fori(m)
	{
		string c;
		cin>>c;
		if(hamisi.find(c)!=hamisi.end())
		++say;
	}
	if(n<m)
	cout<<"NO";
	else if(n>m || (say%2))
	cout<<"YES";
	else 
	cout<<"NO";

}