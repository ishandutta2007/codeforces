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
int n,d,m,a[100010],cnt,tot;
long long b[100010];
int main()
{
	scanf("%d%d%d",&n,&d,&m);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(x<=m)a[++cnt]=x;else b[++tot]=x;
	}
	sort(a+1,a+cnt+1,greater<int>());
	sort(b+1,b+tot+1,greater<int>());
	rep(i,tot)b[i]+=b[i-1];
	long long ans=b[min(tot,(n-1)/(d+1)+1)];
	long long sum=0;
	rep(i,cnt)
	{
		sum+=a[i];
		ans=max(ans,sum+b[min(tot,(n-i-1)/(d+1)+1)]);
	}
	printf("%lld\n",ans);
	return 0;
}