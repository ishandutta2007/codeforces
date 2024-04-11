#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,d=0,nn=0,cr=0,spc[100069],nr[1000069],sr[1000069],z=1e18,inf=1e18;
vector<long long> fz[1000069],al[1000069];
bitset<1000069> vtd;
pair<long long,long long> ed[100069];
queue<long long> q;

void bfs()
{
	long long i,k,l,w,sz;
	
	for(i=1;i<=nn;i++)
	{
		nr[i]=1e18;
		sr[i]=0;
	}
	for(i=1;i<=d;i++)
	{
		q.push(spc[i]);
		nr[spc[i]]=0;
		sr[spc[i]]=i;
	}
	for(;!q.empty();)
	{
		k=q.front();
		w=nr[k];
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(l!=cr&&w+1<nr[l])
			{
				q.push(l);
				nr[l]=w+1;
				sr[l]=sr[k];
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(sr[k]!=sr[l])
		{
			z=min(z,nr[k]+nr[l]+3);
		}
	}
}

int main()
{
	long long i,j,k,l,w,c,sz;
	
	for(i=2;i<=1000000;i++)
	{
		if(!vtd[i])
		{
			nn++;
			for(j=i;j<=1000000;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c^=1);
				if(c)
				{
					fz[j].push_back(nn);
				}
				vtd[j]=1;
			}
		}
	}
	scanf("%lld",&n);
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&w);
		sz=fz[w].size();
		if(!sz)
		{
			z=min(z,1ll);
		}
		else if(sz==1)
		{
			k=fz[w][0];
			if(vtd[k])
			{
				z=min(z,2ll);
			}
			else
			{
				d++;
				spc[d]=k;
			}
			vtd[k]=1;
		}
		else if(sz==2)
		{
			k=fz[w][0];
			l=fz[w][1];
			m++;
			ed[m]={k,l};
			al[k].push_back(l);
			al[l].push_back(k);
		}
	}
	bfs();
	for(cr=1;cr<=168;cr++)
	{
		for(i=1;i<=nn;i++)
		{
			vtd[i]=0;
		}
		d=0;
		sz=al[cr].size();
		for(i=0;i<sz;i++)
		{
			l=al[cr][i];
			if(vtd[l])
			{
				z=min(z,2ll);
			}
			else
			{
				d++;
				spc[d]=l;
			}
			vtd[l]=1;
		}
		bfs();
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}