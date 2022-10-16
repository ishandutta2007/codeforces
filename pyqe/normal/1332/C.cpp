#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[100069][26],mx[100069];

int main()
{
	long long t,rr,i,j,k,p,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<=d-1-i;i++)
		{
			for(j=0;j<26;j++)
			{
				fq[i][j]=0;
			}
			mx[i]=0;
		}
		cin>>s;
		for(i=0;i<n;i++)
		{
			k=s[i]-'a';
			p=min(i%d,d-1-i%d);
			fq[p][k]++;
			mx[p]=max(mx[p],fq[p][k]);
		}
		z=n;
		for(i=0;i<=d-1-i;i++)
		{
			z-=mx[i];
		}
		printf("%lld\n",z);
	}
}