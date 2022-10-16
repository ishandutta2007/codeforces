#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1569];
map<long long,vector<pair<long long,long long>>> pst;

int main()
{
	long long i,j,k,l,sm,sz,mx,e;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm=0;
		for(j=i;j;j--)
		{
			sm+=a[j];
			sz=pst[sm].size();
			if(!sz)
			{
				pst[sm].push_back({0,0});
				sz++;
			}
			k=pst[sm][sz-1].sc;
			if(j>k)
			{
				pst[sm].push_back({j,i});
				mxe=max(mxe,{sz,sm});
			}
		}
	}
	mx=mxe.fr;
	e=mxe.sc;
	printf("%lld\n",mx);
	sz=pst[e].size();
	for(i=1;i<sz;i++)
	{
		k=pst[e][i].fr;
		l=pst[e][i].sc;
		printf("%lld %lld\n",k,l);
	}
}