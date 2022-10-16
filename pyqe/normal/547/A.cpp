#include <bits/stdc++.h>

using namespace std;

long long n,ls[1000069];
map<long long,bool> vtd;

int main()
{
	long long i,ii,p,tg,ml,ad,pst,cl,cd;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld%lld%lld%lld",&p,&tg,&ml,&ad);
		for(i=0;i<n;i++)
		{
			ls[i]=-1;
		}
		pst=-1;
		for(i=0;ls[p]==-1;p=(p*ml+ad)%n,i++)
		{
			ls[p]=i;
			if(p==tg)
			{
				pst=i;
			}
		}
		cl=i-ls[p];
		cd=ls[p];
		for(i=0,p=pst;i<n-(n-1)*(pst<cd);p+=cl,i++)
		{
			if(!ii)
			{
				vtd[p]=1;
			}
			else if(vtd[p])
			{
				printf("%lld\n",p);
				return 0;
			}
		}
	}
	printf("-1\n");
}