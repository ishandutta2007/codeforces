#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=-1,id;
		for(int i=k+1;i<=n;i++)
		{
			int nw=a[i]-a[i-k];
			if(nw%2) nw++;
			nw/=2;
			//printf("i=%d,nw=%d\n",i,nw);
			if(ans==-1) 
			{
				ans=nw,id=(a[i]+a[i-k])/2;
				//printf("--i=%d,id=%d\n",i,id);
			}
			else 
			{
				if(nw<ans)
				{
					ans=nw;
					id=(a[i]+a[i-k])/2;
					//printf("i=%d,id=%d\n",i,id);
				}
			}
		}
		printf("%d\n",id);
	}
	return 0;
}