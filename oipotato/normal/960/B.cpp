#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,k1,k2,a[1010],b[1010];
long long ans;
priority_queue<int> q;
int main()
{
	scanf("%d%d%d",&n,&k1,&k2);k=k1+k2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ans+=1ll*(a[i]-b[i])*(a[i]-b[i]);
		q.push(abs(a[i]-b[i]));
	}
	for(;k--;)
	{
		int u=q.top();q.pop();
		ans+=1-2*u;
		q.push(abs(u-1));
	}
	printf("%lld\n",ans);
	return 0;
}