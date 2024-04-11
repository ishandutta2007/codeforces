#include<cstdio>
#include<iostream>
using namespace std;

const int N=2e6+1e3+7;

int n,a[N];

int ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
			ans++;
		if(a[i]<a[i-1]&&a[i]<a[i+1])
			ans++;
	}
	printf("%d",ans);
}