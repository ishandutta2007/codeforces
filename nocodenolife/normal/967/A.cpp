#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	int h,m;
    	cin>>h>>m;
    	arr[i] = 60*h + m;
    }

    sort(arr, arr+n);
    int answer=arr[n-1]+s+1;
    for(int i=1;i<n;i++)
    {
    	if(i>0 && arr[i]-arr[i-1]>= 2+2*s)
    	{
    		answer = arr[i-1] + s +1;
    		break;
    	}
    }
    if(arr[0]>=s+1)
    	answer=0;

    cout<<answer/60<<" "<<answer%60<<endl;

    return 0;
}