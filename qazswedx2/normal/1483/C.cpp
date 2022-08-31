#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[500005],b[500005],st[500005],tp;
ll f[500005],pre[500005],mx[500005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	pre[0]=-1e18;
	for(int i=1;i<=n;i++)
	{
		ll nw=f[i-1];
		while(tp&&a[st[tp]]>a[i])
		{
			nw=max(nw,mx[tp]);
			tp--;
		}
		st[++tp]=i;
		mx[tp]=nw;
		pre[tp]=max(pre[tp-1],mx[tp]+b[i]);
		f[i]=pre[tp];
	//	printf("i=%d,f=%lld\n",i,f[i]);
	//	for(int j=1;j<=tp;j++)
	//		printf("j=%d,st=%d,mx=%lld,pre=%lld\n",j,st[j],mx[j],pre[j]);
	}
	printf("%lld\n",f[n]);
	return 0;
}