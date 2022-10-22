#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,a[1000001];

int main()
{
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=(long long)(mx-a[i]);
	cout<<ans;
}