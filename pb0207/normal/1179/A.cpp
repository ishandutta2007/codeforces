#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],Q;

int head,tail,q[N*2],mx;

int ans1[N],ans2[N],cnt;

int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]);
	head=1,tail=0;
	for(int i=1;i<=n;i++)
		q[++tail]=a[i];
	while(q[head]!=mx)
	{
		cnt++;
		ans1[cnt]=q[head];
		head++;
		ans2[cnt]=q[head];
		head++;
		if(ans1[cnt]<ans2[cnt])
			q[++tail]=ans1[cnt],q[--head]=ans2[cnt];
		else
			q[++tail]=ans2[cnt],q[--head]=ans1[cnt];
	}
	while(Q--)
	{
		long long x;
		scanf("%lld",&x);
		if(x<=cnt)
			printf("%d %d\n",ans1[x],ans2[x]);
		else
		{
			long long y=(x-cnt-1)%(n-1);
			printf("%d %d\n",mx,q[head+y+1]);
		}
	}
}