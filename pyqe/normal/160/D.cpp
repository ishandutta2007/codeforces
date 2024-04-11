#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,b4=0,dsu[3][100069],ls[2][100069],qq[100069],pr[100069],a[100069],dh[100069],cdh=0,sq[100069];
pair<long long,long long> ed[100069],as[100069];
vector<pair<long long,long long>> al[100069];
string ky[3]={"none","at least one","any"};

long long fd(long long x,long long y)
{
	if(dsu[x][y]!=y)
	{
		dsu[x][y]=fd(x,dsu[x][y]);
	}
	return dsu[x][y];
}

void ae(long long x,long long y,long long w)
{
	if(ls[0][x]<b4)
	{
		al[x].clear();
		ls[0][x]=b4;
	}
	al[x].push_back({y,w});
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	ls[1][x]=b4;
	dsu[2][x]=x;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(ls[1][l]<b4)
		{
			pr[l]=x;
			a[l]=p;
			dfs(l);
		}
	}
	cdh--;
}

int main()
{
	long long i,j,ii,k,l,w,pz,p[2],e;
	pair<long long,long long> mxe;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		as[i]={w,i};
	}
	sort(as+1,as+m+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			dsu[ii][i]=i;
			ls[ii][i]=-1;
		}
	}
	for(i=1;i<=m;i++)
	{
		w=as[i].fr;
		pz=as[i].sc;
		k=ed[pz].fr;
		l=ed[pz].sc;
		k=fd(0,k);
		l=fd(0,l);
		if(k!=l)
		{
			if(fd(1,k)!=fd(1,l))
			{
				dsu[1][fd(1,l)]=fd(1,k);
				ae(k,l,pz);
				ae(l,k,pz);
				sq[pz]=2;
			}
			else
			{
				nn++;
				qq[nn]=pz;
			}
		}
		if(i==m||w<as[i+1].fr)
		{
			for(j=1;j<=nn;j++)
			{
				k=ed[qq[j]].fr;
				l=ed[qq[j]].sc;
				p[0]=fd(0,k);
				p[1]=fd(0,l);
				if(ls[1][p[0]]<b4)
				{
					dfs(p[0]);
				}
				sq[qq[j]]=1;
				for(;p[0]!=p[1];)
				{
					mxe=max(mp(dh[p[0]],0),{dh[p[1]],1});
					e=mxe.sc;
					sq[a[p[e]]]=1;
					dsu[2][p[e]]=fd(2,pr[p[e]]);
					p[e]=fd(2,p[e]);
				}
			}
			for(j=b4+1;j<=i;j++)
			{
				pz=as[j].sc;
				k=ed[pz].fr;
				l=ed[pz].sc;
				dsu[0][fd(0,l)]=fd(0,k);
			}
			nn=0;
			b4=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%s\n",ky[sq[i]].c_str());
	}
}