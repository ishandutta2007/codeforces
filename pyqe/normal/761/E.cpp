#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dh[69],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
vector<long long> al[69];
bitset<69> vtd;
pair<long long,long long> sq[69];

void dfs(long long x,long long b4)
{
	long long i,im=0,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(sz>4)
	{
		printf("NO\n");
		exit(0);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			im+=im==b4;
			dh[l]=dh[x]+1;
			sq[l]={sq[x].fr+(1ll<<n-2-dh[x])*vy[im],sq[x].sc+(1ll<<n-2-dh[x])*vx[im]};
			dfs(l,im^2);
			im++;
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1,-1);
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}