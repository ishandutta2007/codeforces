#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=-1000; 
	sort(a+1,a+n+1);
	if(a[1]==0&&a[2]==0)
	{
		puts("cslnb");
		return 0;
	}
	int sm=0;
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
			sm++;
	if(sm>1)
	{
		puts("cslnb");
		return 0;
	}
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1]&&a[i]-1==a[i-1])
		{
			puts("cslnb");
			return 0;
		}
	ll ans=0;
	int x=1,t=0;
	while(x<=n)
	{
		if(t<=a[x])
			ans+=a[x]-t,t++; 
		x++;
	}
	if(ans&1)
		printf("sjfnb");
	else
		printf("cslnb");
}