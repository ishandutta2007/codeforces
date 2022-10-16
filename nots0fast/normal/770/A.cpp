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
	char z = 'a';
	int n,k;
	cin>>n>>k;
	fori(n)
	{
		cout<<z;
		z= ((z-'a')+1)%k +'a';
	}
}