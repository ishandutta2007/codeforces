#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n , squares;
	cin>>n>>squares;
	
	int arr[n] = {0};
	
	for(int i=0;i<squares;i++)
	{
		int k;
		cin>>k;
		arr[k-1]++;
	}
	int min=squares;
	for(int i=0;i<n;i++)
	{
		if(min>arr[i])
			min = arr[i];
	}
	
	cout<<min<<endl;
	
	return 0;
}