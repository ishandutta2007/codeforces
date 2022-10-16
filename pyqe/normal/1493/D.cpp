#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=2e5,dv=1e9+7;
long long n,fq[200069],pwk,z=1;
vector<pair<long long,long long>> fz[200069];
map<long long,long long> wg[200069];
multiset<long long> ms[200069];

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void ad(long long x,long long w)
{
	long long i,sz=fz[w].size(),k,l,mn;
	
	for(i=0;i<sz;i++)
	{
		k=fz[w][i].fr;
		l=fz[w][i].sc;
		if(!wg[k][x])
		{
			fq[k]++;
			ms[k].insert(0);
		}
		mn=*ms[k].begin()*(fq[k]==n);
		ms[k].erase(ms[k].find(wg[k][x]));
		wg[k][x]+=l;
		ms[k].insert(wg[k][x]);
		z=z*pw(k,*ms[k].begin()*(fq[k]==n)-mn)%dv;
	}
}

int main()
{
	long long t,rr,i,j,k,l,c;
	
	for(i=2;i<=ma;i++)
	{
		if(!fz[i].size())
		{
			for(j=i;j<=ma;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({i,c});
			}
		}
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ad(i,k);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		ad(k,l);
		printf("%lld\n",z);
	}
}