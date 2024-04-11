#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e6,mm=20,dv=1e9+7;
long long n,d,pc[1000069][mm];
vector<pair<long long,long long>> fz[1000069];

int main()
{
	long long t,rr,i,j,k,w,sz,c,z;
	
	for(i=2;i<=ma;i++)
	{
		if(fz[i].empty())
		{
			for(j=i;j<=ma;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({i,c});
			}
		}
	}
	for(i=0;i<mm;i++)
	{
		pc[0][i]=1ll+!!i;
	}
	for(i=1;i<=ma;i++)
	{
		for(j=0;j<mm;j++)
		{
			pc[i][j]=pc[i-1][j];
			if(j)
			{
				pc[i][j]+=pc[i][j-1];
				if(pc[i][j]>=dv)
				{
					pc[i][j]-=dv;
				}
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=1;
		sz=fz[d].size();
		for(i=0;i<sz;i++)
		{
			w=fz[d][i].sc;
			z=z*pc[n][w]%dv;
		}
		printf("%lld\n",z);
	}
}