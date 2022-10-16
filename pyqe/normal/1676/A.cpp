#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,ii,sm[2];
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
		}
		for(i=0;i<6;i++)
		{
			scanf(" %c",&ch);
			sm[i/3]+=ch-'0';
		}
		if(sm[0]==sm[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}