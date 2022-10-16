#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nd,dh[100069],sr[100069],pst[100069],sq[100069];
pair<long long,long long> ed[1100069];
vector<long long> al[100069],vl[17];
queue<long long> q;
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		k=sr[x]^sr[l];
		for(w=0;k>1;k/=2,w++);
		if(!vtd[l])
		{
			sq[l]=sq[x]^w;
			dfs(l);
		}
	}
}

int main()
{
	long long t,rr,i,j,r,k,l,sz,szz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&nd);
		n=1ll<<nd;
		m=nd<<nd-1;
		for(i=0;i<n;i++)
		{
			al[i].clear();
			dh[i]=nd+1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			ed[i]={k,l};
			al[k].push_back(l);
			al[l].push_back(k);
		}
		for(i=0;i<=nd;i++)
		{
			vl[i].clear();
		}
		q.push(0);
		dh[0]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			vl[dh[k]].push_back(k);
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(dh[k]+1<dh[l])
				{
					q.push(l);
					dh[l]=dh[k]+1;
				}
			}
		}
		for(i=0;i<nd;i++)
		{
			k=vl[1][i];
			sr[k]=1ll<<i;
		}
		for(i=2;i<=nd;i++)
		{
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				k=vl[i][j];
				sr[k]=0;
				szz=al[k].size();
				for(r=0;r<szz;r++)
				{
					l=al[k][r];
					if(dh[l]==dh[k]-1)
					{
						sr[k]|=sr[l];
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			pst[sr[i]]=i;
		}
		for(i=0;i<n;i++)
		{
			printf("%lld%c",pst[i]," \n"[i==n-1]);
		}
		if(nd&nd-1)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			vtd[i]=0;
		}
		dfs(0);
		for(i=0;i<n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n-1]);
		}
	}
}