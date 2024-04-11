#include<cstdio>
#include<cstring>

int n,l,r,mid,ans,xx,x1,x2,a[100001],f1[100001][18],f2[100001][18],lo[100001],rr;

int getabs(int x) {return x<0?(-x):x;}
int getmax(int a,int b) {return a>b?a:b;}
int getmin(int a,int b) {return a<b?a:b;}

int gmin(int l,int r)
{
	int len=lo[r-l+1];
	return getmin(f1[l][len],f1[r-(1<<len)+1][len]);
}

int gmax(int l,int r)
{
	int len=lo[r-l+1];
	return getmax(f2[l][len],f2[r-(1<<len)+1][len]);
}

int findmin(int x,int le)
{
	int l=le,r=n,ans=n+1,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (gmin(le,mid)<x) r=mid-1,ans=mid; else l=mid+1;
	}
	return ans;
}

int findmax(int x,int le)
{
	int l=le,r=n,ans=n+1,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (gmax(le,mid)>x) r=mid-1,ans=mid; else l=mid+1;
	}
	return ans;
}

bool check(int p)
{
	rr=getmax(getmin(findmin(x2-p,1),findmax(x2+p,1)),getmin(findmin(x1-p,1),findmax(x1+p,1)))-1;
	for (int i=1; i<=n; i++)
	{
		if (rr<i) return 0;
		if (i<n) rr=getmax(rr,getmin(findmin(a[i]-p,i+1),findmax(a[i]+p,i+1))-1);
	}
	return 1;	
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=100000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d%d%d",&n,&x1,&x2);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),f1[i][0]=f2[i][0]=a[i];
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++)
			if (i+(1<<j)-1<=n)
				f1[i][j]=getmin(f1[i][j-1],f1[i+(1<<(j-1))][j-1]),
				f2[i][j]=getmax(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
			else break;
	l=getabs(x2-x1); r=1e9;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}