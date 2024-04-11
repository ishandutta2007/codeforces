#include <bits/stdc++.h>

using namespace std;

long long n,ma=5e5,fq[2],d0[2],d1[2],d2[2],sq[2],inf=1e18;

int main()
{
	long long i,j,ii,u,k,ln,lb,rb,ub,p,z=inf;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		d0[ii]=inf*u;
		d1[ii]=-inf*u;
		d2[ii]=inf*u;
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		ln=s.length();
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(j=0;j<ln;j++)
		{
			fq[s[j]=='N']++;
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			d0[ii]=min(d0[ii]*u,fq[1]*u)*u;
			d1[ii]=max(d1[ii]*u,(fq[0]-fq[1])*u)*u;
			d2[ii]=min(d2[ii]*u,fq[0]*u)*u;
		}
	}
	for(i=0;i<=ma;i++)
	{
		lb=min(d0[0],i-d1[0]);
		rb=max(d0[1],i-d1[1]);
		ub=max(i-d2[0],d2[1]-i);
		p=max(lb+(rb-lb)/2,(long long)!i);
		k=max(max(p-lb,rb-p),ub);
		if(k<z)
		{
			z=k;
			sq[0]=i;
			sq[1]=p;
		}
	}
	printf("%lld\n",z);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<sq[ii];i++)
		{
			printf("%c","BN"[ii]);
		}
	}
	printf("\n");
}