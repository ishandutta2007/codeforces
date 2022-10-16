#include <bits/stdc++.h>

using namespace std;

long long n,ys,xs,yf,xf,dsu[2569],inf=1e18;
bitset<2569> a;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,ly,lx,z=inf;
	char ch;
	
	scanf("%lld%lld%lld%lld%lld",&n,&ys,&xs,&yf,&xf);
	ys--;
	xs--;
	yf--;
	xf--;
	for(i=0;i<n*n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
		dsu[i]=i;
		if(i%n&&!a[i]&&!a[i-1])
		{
			dsu[fd(i-1)]=fd(i);
		}
		if(i>=n&&!a[i]&&!a[i-n])
		{
			dsu[fd(i-n)]=fd(i);
		}
	}
	for(i=0;i<n*n;i++)
	{
		for(j=0;j<n*n;j++)
		{
			if(fd(i)==fd(ys*n+xs)&&fd(j)==fd(yf*n+xf))
			{
				ly=i/n-j/n;
				lx=i%n-j%n;
				z=min(z,ly*ly+lx*lx);
			}
		}
	}
	printf("%lld\n",z);
}