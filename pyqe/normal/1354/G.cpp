#include <bits/stdc++.h>

using namespace std;

long long n,d,ub=32;

int main()
{
	long long t,rr,i,ii,k,p,lh,rh,md,zz;
	string s;
	
	srand(time(NULL));
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<ub;i++)
		{
			printf("? 1 1\n1 %lld\n",rand()%(n-1)+2);
			fflush(stdout);
			cin>>s;
			if(s[0]=='S')
			{
				printf("! 1\n");
				fflush(stdout);
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			continue;
		}
		for(p=1;1;p+=k)
		{
			k=min(p,n-p);
			if(p+k==n)
			{
				break;
			}
			printf("? %lld %lld\n",k,k);
			for(ii=0;ii<2;ii++)
			{
				for(i=1;i<=k;i++)
				{
					printf("%lld%c",p*ii+i," \n"[i==k]);
				}
			}
			fflush(stdout);
			cin>>s;
			if(s[0]=='F')
			{
				break;
			}
		}
		zz=k;
		for(lh=1,rh=k-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			printf("? %lld %lld\n",md,md);
			for(ii=0;ii<2;ii++)
			{
				for(i=1;i<=md;i++)
				{
					printf("%lld%c",p*ii+i," \n"[i==md]);
				}
			}
			fflush(stdout);
			cin>>s;
			if(s[0]=='F')
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("! %lld\n",p+zz);
		fflush(stdout);
	}
}