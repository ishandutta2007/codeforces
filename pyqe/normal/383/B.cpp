#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,as[200069];
pair<long long,long long> a[100069];
vector<pair<long long,long long>> vl[2][200069];
vector<long long> al[100069];
bitset<100069> vtd;

long long yk(long long x)
{
	long long p=lower_bound(as+1,as+m*2+1,x)-as;
	
	if(p<=m*2&&as[p]==x)
	{
		return p;
	}
	else
	{
		return -1;
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(a[x].fr==n||a[x].sc==n)
	{
		printf("-1\n");
		exit(0);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
}

int main()
{
	long long i,ii,jj,y,x,tg,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&y,&x);
		y=n+1-y;
		a[i]={y,x};
		as[i*2-1]=y;
		as[i*2]=x;
	}
	sort(as+1,as+m*2+1);
	for(i=1;i<=m;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		for(ii=0;ii<2;ii++)
		{
			vl[ii][yk(y)].push_back({x,i});
			swap(y,x);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=m*2;i++)
		{
			sort(vl[ii][i].begin(),vl[ii][i].end());
		}
	}
	for(i=1;i<=m;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				tg=yk(y+ii);
				if(tg==-1)
				{
					continue;
				}
				p=lower_bound(vl[jj][tg].begin(),vl[jj][tg].end(),mp(x+ii*2,0ll))-vl[jj][tg].begin()-1;
				if(p+1)
				{
					al[i].push_back(vl[jj][tg][p].sc);
				}
				swap(y,x);
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		if((y==1||x==1)&&!vtd[i])
		{
			dfs(i);
		}
	}
	printf("%lld\n",n*2-2);
}