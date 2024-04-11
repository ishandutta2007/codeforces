#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;
map<vector<pair<long long,long long>>,long long> fq;
vector<pair<long long,long long>> fz[100069];
bitset<100069> vtd;
vector<pair<long long,long long>> v,vv;

int main()
{
	long long i,j,c,k,sz,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=2;i<=100000;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=100000;j+=i)
			{
				vtd[j]=1;
				for(c=0,k=j;k%i==0;k/=i,c=(c+1)%d);
				if(c%d!=0)
				{
					fz[j].push_back({i,c});
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		v=fz[k];
		vv=v;
		sz=v.size();
		for(j=0;j<sz;j++)
		{
			vv[j].sc=d-vv[j].sc;
		}
		z+=fq[vv];
		fq[v]++;
	}
	printf("%lld\n",z);
}