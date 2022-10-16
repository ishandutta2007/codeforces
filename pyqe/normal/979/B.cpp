#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[3][256],mx[3],inf=1e18;
string ky[4]={"Kuro","Shiro","Katie","Draw"};

int main()
{
	long long i,j,k,z=-inf,e;
	string s;
	
	scanf("%lld",&d);
	for(i=0;i<3;i++)
	{
		cin>>s;
		n=s.length();
		for(j=0;j<n;j++)
		{
			k=s[j];
			fq[i][k]++;
			mx[i]=max(mx[i],fq[i][k]);
		}
	}
	for(i=0;i<3;i++)
	{
		k=min(mx[i]+d,n)-(mx[i]==n&&d==1);
		if(k>z)
		{
			z=k;
			e=i;
		}
		else if(k==z)
		{
			e=3;
		}
	}
	printf("%s\n",ky[e].c_str());
}