#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dh[100069],cdh=0,pr[100069][17],bl[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l][0]=x;
			for(j=1;j-1<bl[pr[l][j-1]];j++)
			{
				pr[l][j]=pr[pr[l][j-1]][j-1];
			}
			bl[l]=j;
			dfs(l);
		}
	}
	cdh--;
}

long long lca(long long x,long long y)
{
	long long i,ii,p[2]={x,y};
	
	for(ii=0;ii<2;ii++)
	{
		for(i=16;i>=0;i--)
		{
			if(i<bl[p[ii]]&&dh[pr[p[ii]][i]]>=dh[p[!ii]])
			{
				p[ii]=pr[p[ii]][i];
			}
		}
	}
	for(i=16;i>=0;i--)
	{
		if(i<bl[p[0]]&&pr[p[0]][i]!=pr[p[1]][i])
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=pr[p[ii]][i];
			}
		}
	}
	if(p[0]!=p[1])
	{
		p[0]=pr[p[0]][0];
	}
	return p[0];
}

long long dis(long long x,long long y)
{
	return dh[x]+dh[y]-dh[lca(x,y)]*2;
}

int main()
{
	long long t,rr,i,ii,k,l,kk,ll,w,cl,nr,p[3],la,e,cd[2],df;
	pair<long long,long long> mxe;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",&kk,&ll,&k,&l,&w);
		cl=dis(kk,ll)+1;
		nr=dis(k,l);
		p[0]=k;
		p[1]=kk;
		p[2]=ll;
		mxe={-1e18,-1};
		for(ii=0;ii<3;ii++)
		{
			la=lca(p[ii],p[(ii+1)%3]);
			mxe=max(mxe,{dh[la],la});
		}
		e=mxe.sc;
		cd[0]=dis(k,e)+dis(e,l);
		cd[1]=min(dis(k,kk)+1+dis(ll,l),dis(k,ll)+1+dis(kk,l));
		df=w-nr;
		if(df>=0&&df%2==0)
		{
			printf("YES\n");
		}
		else
		{
			for(ii=0;ii<2;ii++)
			{
				df=w-cd[ii];
				if((df>=0&&df%2==0)||(df-cl>=0&&(df-cl)%2==0))
				{
					ii=-1;
					break;
				}
			}
			if(ii==-1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}