#include <bits/stdc++.h>

using namespace std;

long long n,d,ps[26][100069];

int main()
{
	long long i,j,k,lh,rh,md,zz;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		for(j=0;j<26;j++)
		{
			ps[j][i]=ps[j][i-1];
		}
		ps[k][i]++;
	}
	for(lh=0,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(j=0,i=0;j!=-1&&i<26;i++)
		{
			for(j=md;j<=n;j++)
			{
				if(ps[i][j]-ps[i][j-md]>=md-d)
				{
					j=-1;
					break;
				}
			}
		}
		if(j==-1)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}