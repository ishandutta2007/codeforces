#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,sqn=316,dh[100069],cdh=0,pst[100069],lg2[200069],nr[100069],uds[369],udn=0;
vector<long long> al[100069];
bitset<100069> vtd;
pair<long long,long long> sp[18][200069];
queue<long long> q;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dh[x]=cdh;
	nn++;
	sp[0][nn]={dh[x],x};
	pst[x]=nn;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			nn++;
			sp[0][nn]={dh[x],x};
		}
	}
	cdh--;
}

pair<long long,long long> qr(long long lh,long long rh)
{
	long long ln=rh-lh+1,e=lg2[ln];
	
	return min(sp[e][lh],sp[e][rh-(1<<e)+1]);
}

long long lca(long long x,long long y)
{
	pair<long long,long long> tmp;
	
	if(pst[x]>pst[y])
	{
		swap(x,y);
	}
	tmp=qr(pst[x],pst[y]);
	return tmp.sc;
}

long long dis(long long x,long long y)
{
	return dh[x]+dh[y]-dh[lca(x,y)]*2;
}

void bfs()
{
	long long i,k,l,w,sz;
	
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		w=nr[k];
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(w+1<nr[l])
			{
				q.push(l);
				nr[l]=w+1;
			}
		}
	}
}

int main()
{
	long long t,rr,i,j,ky,k,l,mn;
	
	for(i=1;i<=200000;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	for(i=1;i<18;i++)
	{
		for(j=1;j<=nn-(1<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<i-1)]);
		}
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	q.push(1);
	nr[1]=0;
	bfs();
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			udn++;
			uds[udn]=k;
			if(udn==sqn)
			{
				for(i=1;i<=udn;i++)
				{
					q.push(uds[i]);
					nr[uds[i]]=0;
				}
				bfs();
				udn=0;
			}
		}
		else if(ky==2)
		{
			mn=nr[k];
			for(i=1;i<=udn;i++)
			{
				mn=min(mn,dis(k,uds[i]));
			}
			printf("%lld\n",mn);
		}
	}
}