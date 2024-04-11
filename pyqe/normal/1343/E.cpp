#include <bits/stdc++.h>

using namespace std;

long long n,m,st[3],a[200069],ps[200069],nr[3][200069],inf=1e18;
vector<long long> al[200069];
queue<long long> q;

int main()
{
	long long t,rr,i,j,k,l,w,sz,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<3;i++)
		{
			scanf("%lld",st+i);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		sort(a+1,a+m+1);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			ps[i]=ps[i-1]+a[i];
		}
		for(i=0;i<3;i++)
		{
			for(j=1;j<=n;j++)
			{
				nr[i][j]=1e18;
			}
			q.push(st[i]);
			nr[i][st[i]]=0;
			for(;!q.empty();)
			{
				k=q.front();
				w=nr[i][k];
				q.pop();
				sz=al[k].size();
				for(j=0;j<sz;j++)
				{
					l=al[k][j];
					if(w+1<nr[i][l])
					{
						q.push(l);
						nr[i][l]=w+1;
					}
				}
			}
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=0;j<3;j++)
			{
				sm+=nr[j][i];
			}
			if(sm<=m)
			{
				z=min(z,ps[sm]+ps[nr[1][i]]);
			}
		}
		printf("%lld\n",z);
	}
}