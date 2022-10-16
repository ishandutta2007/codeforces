#include <bits/stdc++.h>

using namespace std;

long long n,m,sqn,cl[100069],ls[100069],sq[100069],pst[100069],zs=0;
vector<long long> al[100069],vl[100069];
bitset<100069> vtd,vtd2,spc;
queue<long long> q;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(spc[x])
	{
		if(pst[x]<=(zs-1)/2+1)
		{
			for(i=2;i<zs+2-i;i++)
			{
				swap(sq[i],sq[zs+2-i]);
				swap(pst[sq[i]],pst[sq[zs+2-i]]);
			}
		}
		for(i=pst[x]+1;i<=zs;i++)
		{
			spc[sq[i]]=0;
		}
		zs=pst[x];
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l]&&!vtd2[l]&&cl[l])
		{
			dfs(l);
			if(r0)
			{
				zs++;
				sq[zs]=x;
				pst[x]=zs;
				spc[x]=1;
				return;
			}
		}
	}
}

void cyc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(cl[l]&&cl[l]==cl[x]-1)
		{
			cyc(l);
			break;
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(cl[l]&&cl[l]==cl[x]-2)
		{
			vtd.reset();
			r0=0;
			dfs(l);
			break;
		}
	}
	vtd2[x]=0;
	zs++;
	for(i=zs;i-1;i--)
	{
		sq[i]=sq[i-1];
		pst[sq[i]]=i;
	}
	sq[1]=x;
	pst[x]=1;
	spc[x]=1;
}

int main()
{
	long long i,j,k,l,sz,c=0,lh,rh,md;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(lh=0,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*md>=n)
		{
			sqn=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	q.push(1);
	vtd[1]=1;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		c++;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			ls[cl[l]]=c;
			if(!vtd[l])
			{
				q.push(l);
				vtd[l]=1;
			}
		}
		for(cl[k]=1;ls[cl[k]]==c;cl[k]++);
		vl[cl[k]].push_back(k);
		if(cl[k]>=sqn)
		{
			cyc(k);
			printf("2\n%lld\n",zs);
			for(i=1;i<=zs;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==zs]);
			}
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=vl[i].size();
		if(sz>=sqn)
		{
			printf("1\n");
			for(j=0;j<sqn;j++)
			{
				printf("%lld%c",vl[i][j]," \n"[j==sqn-1]);
			}
			break;
		}
	}
}