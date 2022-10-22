#include<bits/stdc++.h>
using namespace std;

const int M=2*1e5+10;
int T,n,k,a[M],minn[M],maxn[M],t[M*2],sum[M*2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
//		memset(a,0,sizeof(a));
//		memset(t,0,sizeof(t));
//		memset(minn,0,sizeof(minn));
//		memset(maxn,0,sizeof(maxn));
//		memset(sum,0,sizeof(sum));
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (int i=1;i<=n/2;i++)
			t[a[i]+a[n-i+1]]++;
		for (int i=1;i<=n/2;i++)
			minn[i]=min(a[n-i+1],a[i]),maxn[i]=max(a[n-i+1],a[i]);
		for (int i=1;i<=n/2;i++)
			sum[1]+=2,sum[minn[i]+1]-=1,sum[maxn[i]+k+1]+=1;
//		for (int i=1;i<=2*k;i++)
//			printf("%3d",i);
//		cout<<endl;
//		for (int i=1;i<=2*k;i++)
//			printf("%3d",sum[i]);
//		cout<<endl;
		for (int i=2;i<=2*k;i++)
			sum[i]+=sum[i-1];
		int ans=9999999;
		for (int i=2;i<=k*2;i++)
			ans=min(ans,sum[i]-t[i]);
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
			a[i]=0,minn[i]=maxn[i]=0;
		for (int i=1;i<=k*2+2;i++)
			t[i]=sum[i]=0;
	}
	return 0;
}