#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,L,a[1000005],b[1000005][2],tans[1000005];
int check(int l,int r)
{
	int ll=0,rr=0;
	for(int i=1;i<=n;i++)
	{
		ll+=l,rr+=r;
		ll=max(ll,a[i]);
		rr=min(rr,a[i+1]);
		if(ll>rr) return 0;
	}
	return rr==a[n+1];
}
inline int F(int x,int l,int r)
{
	return l<=x&&x<=r;
}
void print(int l,int r)
{
//	printf("print:l=%d,r=%d\n",l,r);
	int ll=0,rr=0;
	for(int i=1;i<=n;i++)
	{
		ll+=l,rr+=r;
		ll=max(ll,a[i]);
		rr=min(rr,a[i+1]);
		b[i][0]=ll,b[i][1]=rr;
	}
	int q=L;
	tans[0]=0,tans[n]=L;
	for(int i=n-1;i>0;i--)
	{
		int nwl=b[i][0],nwr=b[i][1];
		if(F(q-nwr,l,r)) q=nwr;
		else if(F(q-nwl,l,r)) q=nwl;
		else if(F(q-l,nwl,nwr)) q=q-l;
		else if(F(q-r,nwl,nwr)) q=q-r;
		else exit(5);
		tans[i]=q;
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",tans[i-1],tans[i]);
}
int main()
{
	scanf("%d%d",&L,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=L;
	int l=0,r=L,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(0,mid)) r=mid-1;
		else l=mid+1;
	}
	int q=l;
	l=0,r=q;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid,q)) l=mid+1;
		else r=mid-1;
	}
	print(r,q);
	return 0;
}