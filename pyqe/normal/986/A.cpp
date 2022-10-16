#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dd,nr[100069][169],inf=1e18;
vector<long long> vl[169],al[100069];
queue<long long> q;

int main()
{
	long long i,j,k,l,w,sz,z;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dd);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		vl[k].push_back(i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=n;j++)
		{
			nr[j][i]=inf;
		}
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			k=vl[i][j];
			q.push(k);
			nr[k][i]=0;
		}
		for(;!q.empty();)
		{
			k=q.front();
			w=nr[k][i];
			q.pop();
			sz=al[k].size();
			for(j=0;j<sz;j++)
			{
				l=al[k][j];
				if(w+1<nr[l][i])
				{
					q.push(l);
					nr[l][i]=w+1;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sort(nr[i]+1,nr[i]+d+1);
		z=0;
		for(j=1;j<=dd;j++)
		{
			z+=nr[i][j];
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}