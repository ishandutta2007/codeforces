#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,nm,a[1000069],ca[1000069][2],sk[1000069];

int main()
{
	long long t,rr,i,j,k,e=0,p,z;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=0;i<n;i++)
	{
		k=(s[i]!='0')+(s[i]=='?');
		if(k!=2)
		{
			if(!nn||(k!=a[nn]&&a[nn]!=-1))
			{
				nn++;
			}
			else if(e)
			{
				ca[nn][0]+=ca[nn][1];
				ca[nn][1]=0;
			}
			a[nn]=k;
			e=0;
		}
		else
		{
			if(!nn)
			{
				nn++;
				a[nn]=-1;
			}
			e=1;
		}
		ca[nn][e]++;
	}
	for(i=1;i<=nn;i++)
	{
		sk[i]=i;
	}
	nm=nn;
	for(i=1;i<=n;i++)
	{
		k=0;
		p=0;
		z=0;
		for(j=1;j<=nm;j++)
		{
			k+=ca[sk[j]][0]+ca[sk[j]][1];
			z+=k/i;
			k=min(k%i,ca[sk[j]][1]*(sk[j]+1==sk[j+1]));
			if(ca[sk[j]-1][1]+ca[sk[j]][0]+ca[sk[j]][1]>i||ca[sk[j]][1]+ca[sk[j]+1][0]+ca[sk[j]+1][1]>i)
			{
				p++;
				sk[p]=sk[j];
			}
		}
		nm=p;
		printf("%lld%c",z," \n"[i==n]);
	}
}