#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <deque>
#include <string>
#include <set>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define form(v) for(int m=0; m<v; m++)
#define forz(v) for(int z=0; z<v; z++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define lli long long int

int main()
{
	int arr[10] = { 6, 2 , 5, 5, 4 , 5 , 6 , 3 , 7 , 6};
	int n;
	cin>>n;
	int sum = 0;
	string eddi = "";
	while(sum<n)
	{
		if(sum+2<=n)
		{
			eddi+="1";
		}
		sum+=2;
	}
	if(sum==n+1)
	{
		eddi[0] = '7';
	}
	cout<<eddi;
}