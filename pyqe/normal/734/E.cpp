#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
bitset<200069> a,vtd;
vector<long long> al[200069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,ii,k,l,w,sz,ww,fh=1;
	pair<long long,long long> mxe;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(ii=0;ii<2;ii++)
	{
		vtd.reset();
		q.push({fh,0});
		vtd[fh]=1;
		mxe={0,fh};
		for(;!q.empty();)
		{
			k=q.front().fr;
			w=q.front().sc;
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(!vtd[l])
				{
					ww=w+(a[k]^a[l]);
					q.push({l,ww});
					vtd[l]=1;
					mxe=max(mxe,{ww,l});
				}
			}
		}
		fh=mxe.sc;
	}
	printf("%lld\n",(mxe.fr+1)/2);
}