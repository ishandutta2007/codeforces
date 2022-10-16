#include <bits/stdc++.h>

using namespace std;

long long n,ky[5]={0,2,0,2,0},a[100069];

int main()
{
	long long t,rr,i,lb,rb;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		for(lb=0;lb<4&&a[lb+1]==ky[lb+1];lb++);
		for(rb=0;rb<4&&a[n-rb]==ky[4-rb];rb++);
		if(lb+rb>=4)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}