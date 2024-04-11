#include <bits/stdc++.h>
using namespace std;
int arr[100007],d[100007];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++) d[i]=arr[i+1]-arr[i]-1;
	sort(d,d+n-1);
	if(k>=n) printf("%d",n);
	else
	{
		int t=n-k,sol=n;
		for(int i=0;i<t;i++) sol+=d[i];
		printf("%d",sol);
	}
}