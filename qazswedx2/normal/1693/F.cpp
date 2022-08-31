#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000005],pre[1000005];
char s[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			a[i]=a[i-1]+(s[i]-'0')*2-1;
		if(a[n]<0)
		{
			reverse(s+1,s+n+1);
			for(int i=1;i<=n;i++)
			{
				s[i]^=1;
				a[i]=a[i-1]+(s[i]-'0')*2-1;
			}
		}
	//	for(int i=1;i<=n;i++)
	//		printf("i=%d,s=%c,a=%d\n",i,s[i],a[i]);
		int fl=0;
		for(int i=0;i<=n;i++)
			if(a[i]==-i&&a[n]==(n-i)-i)
			{
				fl=1;
				break;
			}
		if(fl)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			pre[i]=max(pre[i-1],a[i]);
		int nw=n,ans=0,sum;
		while(nw&&s[nw]=='1') nw--;
		sum=a[nw];
		while(1)
		{
		//	int u=nw;
		//	while(u&&s[u]=='1') u--;
			int v=nw;
			while(v&&pre[v-1]>=sum) v--;
		//	printf("v=%d,nw=%d,sum=%d,ans=%d\n",v,nw,sum,ans);
			sum-=(nw-v)/2;
			nw=(v+nw)/2;
			ans++;
			if(!v) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}