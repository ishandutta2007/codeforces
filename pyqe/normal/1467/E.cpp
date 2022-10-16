#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],as[200069],dh[200069],pst[200069],sbt[200069],ps[200069],z=0;
vector<long long> vl[200069],al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	pst[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

bool cpst(long long x,long long y)
{
	return pst[x]<pst[y];
}

void trv(long long x,long long w)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	z+=!w;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l,w+ps[l]);
		}
	}
}

int main()
{
	long long i,j,r,k,l,sz,tg,szz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]=a[i];
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(as+1,as+n+1,a[i])-as;
		vl[a[i]].push_back(i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		sort(vl[i].begin(),vl[i].end(),cpst);
		sz=vl[i].size();
		if(sz>1)
		{
			l=0;
			for(j=0;j<sz;j++)
			{
				k=vl[i][j];
				if(!j)
				{
					szz=al[k].size();
					for(r=0;r<szz;r++)
					{
						tg=al[k][r];
						if(dh[tg]>dh[k]&&pst[tg]<=pst[vl[i][1]]&&pst[tg]+sbt[tg]-1>=pst[vl[i][sz-1]])
						{
							break;
						}
					}
					if(r<szz)
					{
						ps[1]++;
						ps[tg]--;
						continue;
					}
				}
				if(pst[k]<=pst[l]+sbt[l]-1)
				{
					printf("0\n");
					return 0;
				}
				ps[k]++;
				l=k;
			}
		}
	}
	vtd.reset();
	trv(1,ps[1]);
	printf("%lld\n",z);
}