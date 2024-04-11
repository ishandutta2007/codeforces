#include <bits/stdc++.h>

using namespace std;

long long n,sr[100069];
bitset<100069> cpt,vtd;
vector<long long> fz[100069];

int main()
{
	long long t,rr,i,j,k,l,sz;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=2;i<=n;i++)
	{
		if(!cpt[i])
		{
			for(j=i;j<=n;j+=i)
			{
				cpt[j]=1;
				fz[j].push_back(i);
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='+')
		{
			if(vtd[k])
			{
				printf("Already on\n");
				continue;
			}
			sz=fz[k].size();
			for(i=0;i<sz;i++)
			{
				l=fz[k][i];
				if(sr[l])
				{
					break;
				}
			}
			if(i<sz)
			{
				printf("Conflict with %lld\n",sr[l]);
				continue;
			}
			printf("Success\n");
			vtd[k]=1;
			for(i=0;i<sz;i++)
			{
				l=fz[k][i];
				sr[l]=k;
			}
		}
		else
		{
			if(!vtd[k])
			{
				printf("Already off\n");
				continue;
			}
			printf("Success\n");
			vtd[k]=0;
			sz=fz[k].size();
			for(i=0;i<sz;i++)
			{
				l=fz[k][i];
				sr[l]=0;
			}
		}
	}
}