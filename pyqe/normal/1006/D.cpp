#include <bits/stdc++.h>

using namespace std;

long long a[2][100069],fq[26],d[2],pst[26];

int main()
{
	long long n,i,ii,j,z=0;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
	}
	for(i=1;i<=n/2;i++)
	{
		for(j=0;j<26;j++)
		{
			fq[j]=0;
			d[0]=0;
			d[1]=0;
		}
		for(ii=0;ii<2;ii++)
		{
			fq[a[ii][i]]++;
			pst[a[ii][i]]=ii;
			fq[a[ii][n-i+1]]++;
			pst[a[ii][n-i+1]]=ii;
		}
		for(j=0;j<26;j++)
		{
			if(fq[j]==1)
			{
				d[pst[j]]++;
			}
		}
		z+=max(d[0],d[1]);
		if(d[0]==2&&d[1]==0)
		{
			z--;
		}
	}
	if(n%2==1&&a[0][n/2+1]!=a[1][n/2+1])
	{
		z++;
	}
	printf("%lld\n",z);
}