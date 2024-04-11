#include <bits/stdc++.h>

using namespace std;

long long ln,n,a[200069],fq[2][2];

int main()
{
	long long t,rr,i,ii,jj,ml,z;
	bool bad[2];
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&ln);
		cin>>s;
		n=s.length();
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				fq[ii][jj]=0;
			}
			bad[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]=='D';
			fq[0][a[i]]++;
			bad[a[i]]=1;
			fq[1][a[i]]+=bad[!a[i]];
		}
		z=n+1;
		ml=1;
		for(ii=0;ii<2;ii++)
		{
			z+=(ln-(fq[0][ii]+1))*(fq[1][!ii]+1)*bad[ii];
			ml*=ln-(fq[0][ii]+1);
		}
		z+=ml*(bad[0]&&bad[1]);
		printf("%lld\n",z);
	}
}