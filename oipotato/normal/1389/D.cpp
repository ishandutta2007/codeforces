#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
char s[200010];
int cnt[20];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k,l1,r1,l2,r2;
		scanf("%d%d%d%d%d%d",&n,&k,&l1,&r1,&l2,&r2);
		if(l1>l2)swap(l1,l2),swap(r1,r2);
		if(r2<=r1)
		{
			long long now=1ll*n*(r2-l2);
			if(now>=k){puts("0");continue;}
			long long tmp=min(1ll*n*(l2-l1),k-now);
			long long ans=tmp;now+=tmp;
			tmp=min(1ll*n*(r1-r2),k-now);
			now+=tmp;ans+=tmp;
			ans+=(k-now)*2;
			printf("%lld\n",ans);
		}
		else if(r1>l2)
		{
			long long now=1ll*n*(r1-l2);
			if(now>=k){puts("0");continue;}
			long long tmp=min(1ll*n*(l2-l1),k-now);
			long long ans=tmp;now+=tmp;
			tmp=min(1ll*n*(r2-r1),k-now);
			now+=tmp;ans+=tmp;
			ans+=(k-now)*2;
			printf("%lld\n",ans);
		}
		else
		{
			long long ans=100000ll*k;
			rep(i,n)
			{
				long long tans=1ll*i*(l2-r1);
				long long now=0;
				long long tmp=min(1ll*i*(r1-l1),k-now);
				tans+=tmp;now+=tmp;
				tmp=min(1ll*i*(r2-r1),k-now);
				now+=tmp;tans+=tmp;
				tans+=(k-now)*2;
				ans=min(ans,tans);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}