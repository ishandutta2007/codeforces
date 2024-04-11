#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,m,a[2000005],c[2000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m+2;i++)
			a[i]=c[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		for(int i=m;i>0;i--)
			c[i]=c[i+1]+a[i];
		int fl=1;
		for(int i=1;i<=m;i++)
			if(a[i])
			{
				for(int j=i;j<=m;j+=i)
				{
					int u=c[j]-c[min(j+i,m+1)];
				//	printf("i=%d,j=
					if(u&&!a[j/i])
					{
						fl=0;
						break;
					}
				}
				if(!fl) break;
			}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
}