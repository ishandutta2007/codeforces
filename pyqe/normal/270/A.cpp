#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,r,a;
	
	scanf("%lld",&t);
	for(r=0;r<t;r++)
	{
		scanf("%lld",&a);
		if(a!=180&&360%(180-a)==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}