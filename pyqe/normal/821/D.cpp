#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nr[10069],nr2[2][10069],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},inf=1e18;
pair<long long,long long> a[10069];
vector<long long> vl[2][10069];
deque<pair<long long,long long>> dq;

int main()
{
	long long i,j,ii,im,ky,k,l,y,x,yy,xx,p,sz,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	sort(a+1,a+d+1);
	for(i=1;i<=d;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		for(ii=0;ii<2;ii++)
		{
			vl[ii][y].push_back(i);
			swap(y,x);
		}
		nr[i]=inf;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr2[ii][i]=inf;
		}
		swap(n,m);
	}
	dq.push_back({-1,1});
	nr[1]=0;
	for(;!dq.empty();)
	{
		ky=dq.front().fr;
		k=dq.front().sc;
		dq.pop_front();
		if(ky==-1)
		{
			y=a[k].fr;
			x=a[k].sc;
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=x+vx[im];
				p=lower_bound(a+1,a+d+1,mp(yy,xx))-a;
				if(p<=d&&a[p]==mp(yy,xx)&&nr[k]<nr[p])
				{
					dq.push_front({-1,p});
					nr[p]=nr[k];
				}
			}
			for(ii=0;ii<2;ii++)
			{
				for(i=max(y-1,1ll);i<=min(y+1,n);i++)
				{
					if(nr[k]+1<nr2[ii][i])
					{
						dq.push_back({ii,i});
						nr2[ii][i]=nr[k]+1;
					}
				}
				swap(y,x);
				swap(n,m);
			}
		}
		else
		{
			for(i=max(k-1,1ll);i<=min(k+1,!ky?n:m);i++)
			{
				sz=vl[ky][i].size();
				for(j=0;j<sz;j++)
				{
					l=vl[ky][i][j];
					if(nr2[ky][k]<nr[l])
					{
						dq.push_front({-1,l});
						nr[l]=nr2[ky][k];
					}
				}
			}
			
		}
	}
	z=min(nr2[0][n],nr2[1][m]);
	if(a[d]==mp(n,m))
	{
		z=min(z,nr[d]);
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}