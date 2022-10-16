#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long vx[4]={0,-1,0,1},vy[4]={-1,0,1,0},inf=1e18;
long long n;
pair<long long,long long> a[200069],as[200069];
pair<long long,pair<long long,long long>> nr[200069];
queue<long long> q;

inline long long yk(long long x,long long y)
{
	long long p=lower_bound(as+1,as+n+1,mp(x,y))-as;
	
	if(p<=n&&as[p]==mp(x,y))
	{
		return p;
	}
	else
	{
		return -1;
	}
}

int main()
{
	long long i,im,k,l,x,y,xx,yy;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		a[i]={x,y};
		as[i]=a[i];
		nr[i].fr=inf;
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		x=as[i].fr;
		y=as[i].sc;
		for(im=0;im<4;im++)
		{
			xx=x+vx[im];
			yy=y+vy[im];
			l=yk(xx,yy);
			if(l==-1)
			{
				break;
			}
		}
		if(im<4)
		{
			q.push(i);
			nr[i]={1,{xx,yy}};
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		x=as[k].fr;
		y=as[k].sc;
		for(im=0;im<4;im++)
		{
			xx=x+vx[im];
			yy=y+vy[im];
			l=yk(xx,yy);
			if(l!=-1&&nr[k].fr+1<nr[l].fr)
			{
				q.push(l);
				nr[l]={nr[k].fr+1,nr[k].sc};
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		x=a[i].fr;
		y=a[i].sc;
		k=yk(x,y);
		printf("%lld %lld\n",nr[k].sc.fr,nr[k].sc.sc);
	}
}