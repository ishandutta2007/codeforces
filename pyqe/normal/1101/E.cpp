#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,my=0,mx=0;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld%lld",&ch,&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		if(ch=='+')
		{
			my=max(my,k);
			mx=max(mx,l);
		}
		else
		{
			if(k>=my&&l>=mx)
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