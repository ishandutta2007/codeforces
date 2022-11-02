#include <bits/stdc++.h>
using namespace std;
int arr[100007],b,k;
int main()
{
	cin>>b>>k;
	for(int i=0;i<k;i++) cin>>arr[i];
	if(b%2==0)
	{
		if(arr[k-1]%2==0) printf("even");
		else printf("odd");
	}
	else
	{
		int p;
		for(int i=0;i<k;i++) p+=arr[i];
		if(p%2==0) printf("even");
		else printf("odd");
	}
}