#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],as[200069],sp[2][18][200069],lg2[200069],inf=1e18;
vector<long long> vl[200069];

void spbd()
{
	long long i,j,ii,u,k;
	
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1;i<=n;i++)
		{
			sp[ii][0][i]=a[i];
		}
		for(i=1;1ll<<i<=n;i++)
		{
			for(j=1;j<=n-(1ll<<i)+1;j++)
			{
				sp[ii][i][j]=min(sp[ii][i-1][j]*u,sp[ii][i-1][j+(1ll<<i-1)]*u)*u;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(lg2[i]=0,k=i;k>1;k/=2,lg2[i]++);
	}
}

long long qr(long long ky,long long lh,long long rh)
{
	long long u=!ky*2-1,e;
	
	if(lh>rh)
	{
		return inf*u;
	}
	e=lg2[rh-lh+1];
	return min(sp[ky][e][lh]*u,sp[ky][e][rh-(1ll<<e)+1]*u)*u;
}

int main()
{
	long long t,rr,i,j,l,sz,mn,mx,lb,rb;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
			vl[i].clear();
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			a[i]=lower_bound(as+1,as+n+1,a[i])-as;
			vl[a[i]].push_back(i);
		}
		spbd();
		mn=inf;
		mx=-inf;
		for(i=n;i;i--)
		{
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				l=vl[i][j];
				lb=min(mn,l);
				rb=max(mx,l);
				if(qr(1,1,lb-1)==i&&qr(0,lb,rb)==i&&qr(1,rb+1,n)==i)
				{
					printf("YES\n%lld %lld %lld\n",lb-1,rb-lb+1,n-rb);
					i=-2;
					break;
				}
			}
			if(i==-2)
			{
				break;
			}
			for(j=0;j<sz;j++)
			{
				l=vl[i][j];
				mn=min(mn,l);
				mx=max(mx,l);
			}
		}
		if(i!=-2)
		{
			printf("NO\n");
		}
	}
}