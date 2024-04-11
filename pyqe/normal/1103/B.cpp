#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,lh,rh,md,zz;
	string s;
	char ch;
	
	for(;cin>>s;)
	{
		if(s[0]!='s')
		{
			break;
		}
		for(ch='y',i=0;ch=='y';i++)
		{
			printf("? %lld %lld\n",(1ll<<i)/2,1ll<<i);
			fflush(stdout);
			scanf(" %c",&ch);
		}
		i--;
		for(lh=(1<<i)/2+1,rh=1<<i;lh<=rh;)
		{
			md=(lh+rh)/2;
			printf("? %lld %lld\n",(1ll<<i)/2,md);
			fflush(stdout);
			scanf(" %c",&ch);
			if(ch=='x')
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("! %lld\n",zz);
		fflush(stdout);
	}
}