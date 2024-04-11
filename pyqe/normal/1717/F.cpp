#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,nn[3],nm=0,ttl=0,nv=0,flw,a[10069],dg[10069],wg[100069],vi[100069],z=0;
bitset<10069> kd;
pair<long long,long long> ed[3][10069];
vector<pair<long long,long long>> al[100069];
bool r0;

inline void ae(long long x,long long y,long long w)
{
	al[x].push_back({y,nm});
	al[y].push_back({x,nm+1});
	wg[nm]=w;
	nm+=2;
}

void dfs(long long x,long long cw)
{
	long long i,sz=al[x].size(),l,p;
	
	vi[x]=nv;
	if(x==n+m+1)
	{
		flw=cw;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(wg[p]&&vi[l]<nv)
		{
			dfs(l,min(cw,wg[p]));
			if(r0)
			{
				wg[p]-=flw;
				wg[p^1]+=flw;
				return;
			}
		}
	}
}

inline void mxf()
{
	for(r0=1;r0;)
	{
		r0=0;
		flw=0;
		nv++;
		dfs(0,inf);
		z+=flw;
	}
}

int main()
{
	long long i,j,k,l,l2,p,e,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		kd[i]=k;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		e=kd[k]+kd[l];
		nn[e]++;
		ed[e][nn[e]]={k,l};
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		if(kd[i])
		{
			a[i]+=dg[i];
			if(a[i]%2||a[i]<0||a[i]>dg[i]*2)
			{
				printf("NO\n");
				return 0;
			}
			a[i]/=2;
			ttl+=a[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		if(kd[i])
		{
			ae(0,i,a[i]);
		}
	}
	for(i=1;i<=nn[2];i++)
	{
		k=ed[2][i].fr;
		l=ed[2][i].sc;
		ae(k,n+i,1);
		ae(l,n+i,1);
		ae(n+i,n+m+1,1);
	}
	mxf();
	if(z<nn[2])
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=nn[1];i++)
	{
		k=ed[1][i].fr;
		l=ed[1][i].sc;
		if(!kd[k])
		{
			swap(k,l);
		}
		ae(k,n+nn[2]+i,1);
		ae(n+nn[2]+i,n+m+1,1);
	}
	mxf();
	if(z<ttl)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(i=1;i<=nn[2];i++)
	{
		k=ed[2][i].fr;
		l=ed[2][i].sc;
		sz=al[n+i].size();
		for(j=0;j<sz;j++)
		{
			l2=al[n+i][j].fr;
			p=al[n+i][j].sc;
			if(l2<=n&&wg[p])
			{
				if(l2!=l)
				{
					swap(k,l);
				}
				break;
			}
		}
		printf("%lld %lld\n",k,l);
	}
	for(i=1;i<=nn[1];i++)
	{
		k=ed[1][i].fr;
		l=ed[1][i].sc;
		if(kd[l])
		{
			swap(k,l);
		}
		sz=al[n+nn[2]+i].size();
		for(j=0;j<sz;j++)
		{
			l2=al[n+nn[2]+i][j].fr;
			p=al[n+nn[2]+i][j].sc;
			if(l2<=n&&wg[p])
			{
				swap(k,l);
				break;
			}
		}
		printf("%lld %lld\n",k,l);
	}
	for(i=1;i<=nn[0];i++)
	{
		k=ed[0][i].fr;
		l=ed[0][i].sc;
		printf("%lld %lld\n",k,l);
	}
}