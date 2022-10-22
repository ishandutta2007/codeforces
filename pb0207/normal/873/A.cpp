#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k,x,a[101];

int main()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=1;i<=n-k;i++)
		ans+=a[i];
	ans+=k*x;
	cout<<ans;
}