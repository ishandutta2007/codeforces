#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a,b,ans;

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n-1;i++)
		ans=max(ans,min(a/i,b/(n-i)));
	cout<<ans;
}