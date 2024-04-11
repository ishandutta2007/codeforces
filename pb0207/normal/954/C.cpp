#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n;

ll a[N],x,y;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		puts("YES");
		puts("1000000000 1000000000");
		return 0;
	}
	int p;
	ll t=1;
	for(p=1;p<n;p++)
	{
		t=a[p+1]-a[p];
		t=t<0?-t:t;
		if(t==1)
			continue;
		else
			break;
	}
	for(int i=p;i<n;i++)
	{
		ll w=a[i+1]-a[i];
		w=w<0?-w:w;
		if(w!=1&&w!=t)
		{
			puts("NO");
			return 0;
		}
	}
	if(t==0)
	{
		puts("NO");
		return 0;
	}
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]==1&&t!=1&&a[i-1]%t==0)
		{
			puts("NO");
			return 0;
		}
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]==-1&&t!=1&&a[i]%t==0)
		{
			puts("NO");
			return 0;
		}
	for(int i=1;i<=n;i++)
		if(a[i]>(ll)(1e9)*t)
		{
			puts("NO");
			return 0;
		}
	puts("YES");	
	printf("%lld %lld",(ll)1e9,t);
}