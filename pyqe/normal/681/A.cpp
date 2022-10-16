#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		scanf("%lld%lld",&k,&l);
		if(k>=2400&&k<l)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}