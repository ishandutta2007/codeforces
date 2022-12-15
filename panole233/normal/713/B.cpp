#include<bits/stdc++.h>
using namespace std;

int xl1,xr1,yl1,yr1,n,l,r,mid,xl2,yl2,xr2,yr2;

int query(int xl,int yl,int xr,int yr)
{
	printf("? %d %d %d %d\n",xl,yl,xr,yr),fflush(stdout);
	int ans; scanf("%d",&ans); return ans;
}

int main()
{
	scanf("%d",&n);
	l=1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,1,mid,n)==2) xr2=mid,r=mid-1; else l=mid+1;
	}
	xr1=xr2,l=1,r=xr1-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,1,mid,n)==1) xr1=mid,r=mid-1; else l=mid+1;
	}
	l=1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,1,n,mid)==2) yr2=mid,r=mid-1; else l=mid+1;
	}
	yr1=yr2,l=1,r=yr1-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,1,n,mid)==1) yr1=mid,r=mid-1; else l=mid+1;
	}
	l=1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(mid,1,n,n)==2) xl1=mid,l=mid+1; else r=mid-1;
	}
	xl2=xl1,l=xl1+1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(mid,1,n,n)==1) xl2=mid,l=mid+1; else r=mid-1;
	}
	l=1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,mid,n,n)==2) yl1=mid,l=mid+1; else r=mid-1;
	}
	yl2=yl1,l=yl1+1,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (query(1,mid,n,n)==1) yl2=mid,l=mid+1; else r=mid-1;
	}
	if (xl1!=xl2&&xr1!=xr2&&xl2<=xr1) 
	{
		if (query(xl2,1,xr1,n)==1) swap(xl1,xl2);
	}
	if (yl1!=yl2&&yr1!=yr2&&yl2<=yr1)
	{
		if (query(1,yl2,n,yr1)==1) swap(yl1,yl2);
	}
	if (!(query(xl1,yl1,xr1,yr1)==1&&query(xl2,yl2,xr2,yr2)==1))
		swap(yl1,yl2),swap(yr1,yr2);
	printf("! %d %d %d %d %d %d %d %d\n",xl1,yl1,xr1,yr1,xl2,yl2,xr2,yr2),fflush(stdout);
	return 0;
}