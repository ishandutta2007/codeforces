#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long m,a[1000001];
int n,x,l[2][1000001],r[2][1000001],bn[2];

void solve(long long k,int nw)
{
	if (nw==-1)
	{
		printf("%I64d\n",a[l[0][1]]^a[l[0][2]]);
		return;
	}
	int mid,ansx,ansy,L,R,lx,rx,ly,ry,Y=(nw&1),X=(Y^1);
	long long sum=0;
	for (int j=1; j<=bn[X]; j+=2)
	{
		lx=l[X][j]; rx=r[X][j];
		ly=l[X][j+1]; ry=r[X][j+1];
		ansx=(a[lx]>>nw&1)?(lx):(rx+1); 
		ansy=(a[ly]>>nw&1)?(ly):(ry+1);
		if ((a[lx]>>nw&1)^(a[rx]>>nw&1)) 
		{
			L=lx; R=rx;
			while (L<=R)
			{
				mid=(L+R)>>1;
				if (a[mid]>>nw&1) ansx=mid,R=mid-1; else L=mid+1;
			}
		}
		if ((a[ly]>>nw&1)^(a[ry]>>nw&1))
		{
			L=ly; R=ry;
			while (L<=R)
			{
				mid=(L+R)>>1;
				if (a[mid]>>nw&1) ansy=mid,R=mid-1; else L=mid+1;
			}
		}
		sum+=1ll*(ansx-lx)*(ansy-ly)+1ll*(rx-ansx+1)*(ry-ansy+1);
	}
	bn[Y]=0;
	if (sum>=k)
	{
		for (int j=1; j<=bn[X]; j+=2)
		{
			lx=l[X][j]; rx=r[X][j];
			ly=l[X][j+1]; ry=r[X][j+1];
			ansx=(a[lx]>>nw&1)?(lx):(rx+1); 
			ansy=(a[ly]>>nw&1)?(ly):(ry+1);
			if ((a[lx]>>nw&1)^(a[rx]>>nw&1)) 
			{
				L=lx; R=rx;
				while (L<=R)
				{
					mid=(L+R)>>1;
					if (a[mid]>>nw&1) ansx=mid,R=mid-1; else L=mid+1;
				}
			}
			if ((a[ly]>>nw&1)^(a[ry]>>nw&1))
			{
				L=ly; R=ry;
				while (L<=R)
				{
					mid=(L+R)>>1;
					if (a[mid]>>nw&1) ansy=mid,R=mid-1; else L=mid+1;
				}
			}
			if (lx<ansx&&ly<ansy) l[Y][++bn[Y]]=lx,r[Y][bn[Y]]=ansx-1,l[Y][++bn[Y]]=ly,r[Y][bn[Y]]=ansy-1;
			if (ansx<=rx&&ansy<=ry) l[Y][++bn[Y]]=ansx,r[Y][bn[Y]]=rx,l[Y][++bn[Y]]=ansy,r[Y][bn[Y]]=ry;
		}
	} else
	{
		k-=sum;
		for (int j=1; j<=bn[X]; j+=2)
		{
			lx=l[X][j]; rx=r[X][j];
			ly=l[X][j+1]; ry=r[X][j+1];
			ansx=(a[lx]>>nw&1)?(lx):(rx+1); 
			ansy=(a[ly]>>nw&1)?(ly):(ry+1);
			if ((a[lx]>>nw&1)^(a[rx]>>nw&1)) 
			{
				L=lx; R=rx;
				while (L<=R)
				{
					mid=(L+R)>>1;
					if (a[mid]>>nw&1) ansx=mid,R=mid-1; else L=mid+1;
				}
			}
			if ((a[ly]>>nw&1)^(a[ry]>>nw&1))
			{
				L=ly; R=ry;
				while (L<=R)
				{
					mid=(L+R)>>1;
					if (a[mid]>>nw&1) ansy=mid,R=mid-1; else L=mid+1;
				}
			}
			if (lx<ansx&&ansy<=ry) l[Y][++bn[Y]]=lx,r[Y][bn[Y]]=ansx-1,l[Y][++bn[Y]]=ansy,r[Y][bn[Y]]=ry;
			if (ansx<=rx&&ly<ansy) l[Y][++bn[Y]]=ansx,r[Y][bn[Y]]=rx,l[Y][++bn[Y]]=ly,r[Y][bn[Y]]=ansy-1;
		}
	}
	solve(k,nw-1);
}

int main()
{
	scanf("%d%I64d",&n,&m); a[1]=0;
	for (int i=2; i<=n; i++) scanf("%d%I64d",&x,&a[i]),a[i]^=a[x];
	sort(a+1,a+1+n); l[0][1]=1; r[0][1]=n; l[0][2]=1; r[0][2]=n; bn[0]=2;
	solve(m,61);
	return 0;
}