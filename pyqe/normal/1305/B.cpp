#include <bits/stdc++.h>

using namespace std;

long long n,sq[2][50069],zs=0;
bitset<100069> a;

int main()
{
	long long i,ii,u,p[2];
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='(';
	}
	p[0]=0;
	p[1]=n+1;
	for(zs=0;1;zs++)
	{
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(p[ii]+=u;p[0]<=p[1]&&a[p[ii]]==ii;p[ii]+=u);
			if(p[0]>p[1])
			{
				break;
			}
			sq[ii][zs+1]=p[ii];
		}
		if(p[0]>p[1])
		{
			break;
		}
	}
	if(!zs)
	{
		printf("0\n");
	}
	else
	{
		printf("1\n%lld\n",zs*2);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=1+(zs-1)*ii;i&&i<=zs;i+=u)
			{
				printf("%lld%c",sq[ii][i]," \n"[ii&&i==1]);
			}
		}
	}
}