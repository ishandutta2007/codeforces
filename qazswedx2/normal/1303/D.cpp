#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,m,a[100005],f[105],g[105];
ll n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<=30;i++)
			f[i]=0,g[i]=0;
		scanf("%lld%d",&n,&m);
		ll sum=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum<n)
		{
			printf("-1\n");
			continue;
		}
		sort(a+1,a+m+1);
		for(int i=0;i<=30;i++)
		{
			for(int j=1;j<=m;j++)
				if((1<<i)==a[j])
					f[i]++,g[i]++;
		}
		for(int i=30;i>=0;i--)
		{
			while(f[i]&&n>=(1<<i))
			{
				n-=(1<<i);
				f[i]--;
			}
			if(f[i]) break;
		}
		int ans=0;
		for(int i=0;i<=30;i++)
		{
			if(n&(1<<i))
			{
				n-=(1<<i);
				f[i]--;
			}
			if(f[i]<0) f[i]+=2,f[i+1]--,ans++;
			if(f[i]>=2) f[i+1]+=f[i]/2;
		}
		printf("%d\n",ans);
		/*int ans=1e9,nw=1e9;
		ll tn=n;
		
		if(!n)
		{
			printf("0\n");
			continue;
		}
		for(int i=30;i>=0;i--)
		{
			while(f[i]&&tn>=(1<<i))
			{
				tn-=(1<<i);
				f[i]--;
			}
			if(f[i])
			{
				int ttn=tn;
				for(int j=i-1;j>=0;j--)
					g[j]=f[j];
				while(1)
				{
					int nww=(ttn&-ttn);
					for(int j=i-1;j>=0;j--)
					{
						while(g[j]&&nww>=(1<<j))
							nww-=(1<<j),g[j]--; 
					}
					//printf("ttn=%d,nww=%d\n",ttn,nww);
					if(!nww) ttn-=(ttn&-ttn);
					else break;
				}
				int qwq=0;
				for(int j=30;j>=0;j--)
					if((ttn&-ttn)==(1<<j))
						qwq=j;
				ans=min(ans,i-qwq);
			}
		}
		printf("%d\n",ans);*/ 
	}
	return 0;
}