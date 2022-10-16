#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define lli long long int
int main()
{
	lli n,k;
	cin>>n>>k;
	lli arr[n];
	fori(n)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	lli maxx = 0;
	for(int i=1; i<n; i++)
	{
		if((arr[i]-arr[0])%k!=0)
		{
			cout<<-1;
			return 0;
		}
		else
		{
			maxx += (arr[i]-arr[0])/k;
		}
	}
	cout<<maxx;
}