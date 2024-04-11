#include <bits/stdc++.h>

using namespace std;

const long long ma=26;
long long n,a[200069],sq[200069],zs;
vector<long long> vl[ma];

int main()
{
	long long t,rr,i,j,u,k,sz;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<ma;i++)
		{
			vl[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			vl[a[i]].push_back(i);
		}
		u=(a[n]>=a[1])*2-1;
		zs=0;
		for(i=a[1];1;i+=u)
		{
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				k=vl[i][j];
				zs++;
				sq[zs]=k;
			}
			if(i==a[n])
			{
				break;
			}
		}
		printf("%lld %lld\n",abs(a[1]-a[n]),zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}