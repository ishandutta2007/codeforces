#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][3];
vector<long long> pm,sq;
map<pair<long long,long long>,vector<long long>> al;
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,j,r,sz,l;
	
	vtd[x]=1;
	for(i=0;i<3;i++)
	{
		sz=al[{a[x][i],a[x][(i+1)%3]}].size();
		for(j=0;j<sz;j++)
		{
			l=al[{a[x][i],a[x][(i+1)%3]}][j];
			{
				if(!vtd[l])
				{
					for(r=0;a[l][r]!=a[x][i];r++);
					swap(a[l][r],a[l][0]);
					for(r=0;a[l][r]!=a[x][(i+1)%3];r++);
					swap(a[l][r],a[l][2]);
					dfs(l);
				}
			}
		}
		if(sz==1)
		{
			pm.push_back(a[x][(i+1)%3]);
		}
	}
	sq.push_back(x);
}

int main()
{
	long long t,rr,i,j,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		al.clear();
		for(i=1;i<=n-2;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%lld",&a[i][j]);
			}
			for(j=0;j<3;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					al[{a[i][j],a[i][(j+1+ii)%3]}].push_back(i);
				}
			}
			vtd[i]=0;
		}
		pm.clear();
		sq.clear();
		dfs(1);
		for(i=0;i<n;i++)
		{
			printf("%lld%c",pm[i]," \n"[i==n-1]);
		}
		for(i=0;i<n-2;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n-3]);
		}
	}
}