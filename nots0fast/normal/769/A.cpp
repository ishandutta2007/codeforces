#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <iomanip>
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
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int minn = 110000;
    int maxx = -1;
    fori(n)
    {
    	cin>>arr[i];
    	if(arr[i]<minn)
    	{
    		minn = arr[i];
		}
		if(arr[i]>maxx)
		{
			maxx = arr[i];
		}
	}
	cout<<(minn+maxx)/2;
}