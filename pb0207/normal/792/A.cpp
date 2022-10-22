#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,a[200001];

int tot;

long long ans=1e16;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		if(a[i+1]-a[i]<=ans)
		{
			if(a[i+1]-a[i]==ans)
				tot++;
			else
				tot=1;
			ans=a[i+1]-a[i];
		}
	cout<<ans<<" "<<tot;
}