#include <bits/stdc++.h>

using namespace std;

long long n,m,st[2],nr[2][1069];
vector<long long> al[1069];
queue<long long> q;
bitset<1069> vtd[1069];

int main()
{
	long long i,j,ii,k,l,w,sz,z=0;
	
	scanf("%lld%lld%lld%lld",&n,&m,st,st+1);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		vtd[k][l]=1;
		vtd[l][k]=1;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr[ii][i]=1e18;
		}
		q.push(st[ii]);
		nr[ii][st[ii]]=0;
		for(;!q.empty();)
		{
			k=q.front();
			w=nr[ii][k];
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(w+1<nr[ii][l])
				{
					q.push(l);
					nr[ii][l]=w+1;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(!vtd[i][j]&&min(nr[0][i]+1+nr[1][j],nr[1][i]+1+nr[0][j])>=nr[0][st[1]])
			{
				z++;
			}
		}
	}
	printf("%lld\n",z);
}