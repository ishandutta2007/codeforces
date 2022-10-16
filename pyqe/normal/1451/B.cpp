#include <bits/stdc++.h>

using namespace std;

long long n,mn[2],mx[2];
bitset<100069> a;

int main()
{
	long long tt,rrr,t,rr,i,ii,k,l;
	char ch;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=n+1;
			mx[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			mn[a[i]]=min(mn[a[i]],i);
			mx[a[i]]=i;
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			if(mn[a[k]]<k||mx[a[l]]>l)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}