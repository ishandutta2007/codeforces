#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  mod(int a)
{
	if(a>0)
		return a;
	return -a;
}

int main() {
    int n;
    cin>>n;

    int one=0,two=0;
    int arr[n/2];
    for(int i=0;i<n/2;i++)
    {
    	cin>>arr[i];
    }
    sort(arr, arr+n/2);
    for(int i=1;i<=n/2;i++)
    {
    	int k = arr[i-1];
    	one+= mod( k - (2*i));
    	two+= mod( k - (2*i-1));

    }
    int ans = one>two?two:one;
    cout<<ans<<endl;
    return 0;
}