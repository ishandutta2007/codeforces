#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,a[1000005];
ll ans=0;
priority_queue<ll> pq;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;i++)
		pq.push(0);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)
	{
		ll nw=pq.top();
		pq.pop();
		ans+=nw;
		pq.push(a[i]+nw);
	}
	printf("%lld\n",ans);
	return 0;
}