#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=998244353,inf=1e18;
long long n,m,nr[469][469],pr[469][469],dg[469];
pair<long long,long long> ed[669];
vector<long long> al[469];
queue<long long> q;
bitset<469> spc;

int main()
{
	long long i,j,r,k,l,sz,p,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			nr[i][j]=inf;
		}
		q.push(i);
		nr[i][i]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			sz=al[k].size();
			for(j=0;j<sz;j++)
			{
				l=al[k][j];
				if(nr[i][k]+1<nr[i][l])
				{
					q.push(l);
					nr[i][l]=nr[i][k]+1;
					if(!pr[i][l])
					{
						pr[i][l]=k;
					}
					else
					{
						pr[i][l]=-1;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			spc.reset();
			for(p=j;p>0;p=pr[i][p])
			{
				spc[p]=1;
			}
			if(p)
			{
				printf("0%c"," \n"[j==n]);
				continue;
			}
			for(r=1;r<=n;r++)
			{
				dg[r]=0;
			}
			for(r=1;r<=m;r++)
			{
				k=ed[r].fr;
				l=ed[r].sc;
				if(nr[i][k]>nr[i][l])
				{
					swap(k,l);
				}
				if(!(nr[i][k]<nr[i][l]&&nr[j][k]<nr[j][l]))
				{
					continue;
				}
				dg[l]++;
			}
			z=1;
			for(r=1;r<=n;r++)
			{
				if(!spc[r])
				{
					z=z*dg[r]%dv;
				}
			}
			printf("%lld%c",z," \n"[j==n]);
		}
	}
}