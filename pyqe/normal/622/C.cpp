#include <bits/stdc++.h>

using namespace std;

long long n,ls[1000069];
vector<long long> pst[2][1000069];

int main()
{
	long long t,rr,i,k,l,w,sz,p;
	
	for(i=1;i<=1000000;i++)
	{
		pst[0][i].push_back(0);
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!ls[k]||i>ls[k]+1)
		{
			pst[0][k].push_back(i+1);
			pst[1][k].push_back(i-1);
		}
		else
		{
			sz=pst[0][k].size();
			pst[0][k][sz-1]++;
		}
		ls[k]=i;
	}
	for(i=1;i<=1000000;i++)
	{
		pst[1][i].push_back(n+1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		p=*lower_bound(pst[1][w].begin(),pst[1][w].end(),k);
		p=*(upper_bound(pst[0][w].begin(),pst[0][w].end(),p)-1);
		p=max(p,k);
		if(p>l)
		{
			p=-1;
		}
		printf("%lld\n",p);
	}
}