#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],mn[N][21],mx[N][21],Log[N];

long long b[N];

void RMQ(int nn)
{
	for(int i=1;i<=nn;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=nn;++i)
	  mn[i][0]=a[i];
	for(int j=1;(1<<j)<=nn;++j)
	  for(int i=1;i+(1<<(j-1))<=nn;++i)
	    mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
}

void RMQQ(int nn)
{
	for(int i=1;i<=nn;++i)
	  mx[i][0]=b[i];
	for(int j=1;(1<<j)<=nn;++j)
	  for(int i=1;i+(1<<(j-1))<=nn;++i)
	    mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
}

int qmx(int l,int r)
{
	int k=Log[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}

int qmn(int l,int r)
{
	int k=Log[r-l+1]-1;
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n+1;i<=n*2;i++)
		a[i]=a[i-n];
	for(int i=n*2+1;i<=n*3;i++)
		a[i]=a[i-n];
	int mnn=1e9,mxx=0;
	for(int i=1;i<=n;i++)
		 mnn=min(mnn,a[i]),mxx=max(mxx,a[i]);
	if(mnn*2>=mxx)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",-1);
		return 0;
	}
	RMQ(n*3);
	for(int i=1;i<=n*2;i++)
		b[i]=0x7fffffff;
	for(int i=1;i<=n*2;i++)
	{
		int l=0,r=n;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(qmn(i,i+mid)*2<a[i])
				r=mid;
			else
				l=mid;
		}
		if(l!=n-1)
			b[i]=r;
	}
	for(int i=2*n-1;i>=1;i--)
		if(b[i+1]+1<b[i])
			b[i]=b[i+1]+1;
	for(int i=1;i<=n;i++)
		printf("%lld ",min(b[i],b[i+n]));
}