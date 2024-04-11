#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,nn=0,pc[269][269],ex[269],sbt[269],pwk;
vector<long long> al[269];
bitset<269> vtd,spc;
bool r0;

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

void dfs(long long x,long long y)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(x==y)
	{
		nn++;
		ex[nn]=x;
		spc[x]=1;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l,y);
			if(r0)
			{
				nn++;
				ex[nn]=x;
				spc[x]=1;
				return;
			}
		}
	}
}

void dfs2(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l]&&!spc[l])
		{
			dfs2(l);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long i,j,r,k,l,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	pc[2][1]=0;
	pc[2][2]=1;
	for(i=3;i<=n;i++)
	{
		pc[i][1]=0;
		for(j=2;j<i;j++)
		{
			pc[i][j]=(pc[i-1][j-1]+pc[i-1][j])*pw(2,dv-2)%dv;
		}
		pc[i][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			vtd.reset();
			r0=0;
			nn=0;
			spc.reset();
			dfs(i,j);
			vtd.reset();
			for(r=1;r<=nn;r++)
			{
				dfs2(ex[r]);
				z=(z+sbt[ex[r]]*pw(n,dv-2)%dv*pc[nn][r])%dv;
			}
		}
	}
	printf("%lld\n",z);
}