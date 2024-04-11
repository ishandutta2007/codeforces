#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],lis[200069],sq[200069];

int main()
{
	long long i,j,p,mx=-1e18;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		lis[i]=1e18;
	}
	lis[0]=-1e18;
	for(i=n;i;i--)
	{
		p=lower_bound(lis,lis+n+1,a[i])-lis;
		lis[p]=min(lis[p],a[i]);
		sq[i]=p;
		mx=max(mx,p);
	}
	if(mx>2)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld",sq[i]-1);
		}
		printf("\n");
	}
}