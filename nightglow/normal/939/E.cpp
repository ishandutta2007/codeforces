#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 500005

using namespace std;

int i,j,m,n,p,k,a[N],ty,x;

long long b[N];

double check(int x)
{
		return 1.*(b[x-1]+a[n])/x;
}

int main()
{
		scanf("%d",&m);
		for (;m--;)
		{
				scanf("%d",&ty);
				if (ty==1) 
				{
						scanf("%d",&x);
						a[++n]=x;
						b[n]=b[n-1]+x;
				}
				else
				{
						int l=1,r=n;
						while (r-l>10)
						{
							int len=(r-l+1)/3,mid1=l+len,mid2=mid1+len;
							if (check(mid1)<check(mid2)) r=mid2;
							else l=mid1;
						}
						double ans=0;
						for (i=l;i<=r;++i) ans=max(ans,a[n]-check(i));
						printf("%.10lf\n",ans);
				}
		}
}