#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[100005],at,m=13,cnt[100005];
ll ans[15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<(1<<m);i++)
	{
		cnt[i]=cnt[i/2]+i%2;
		if(cnt[i]!=6) continue;
		a[++at]=i;
		if(at==n) break;
	}
	for(int i=0;i<m;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i)) k++;
		if(!k) continue;
		printf("? %d ",k);
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				printf("%d ",j);
		printf("\n");
		fflush(stdout);
		scanf("%lld",&ans[i]);
	}
	printf("! ");
	for(int i=1;i<=n;i++)
	{
		ll nw=0;
		for(int j=0;j<m;j++)
			if(!(a[i]&(1<<j)))
				nw|=ans[j];
		printf("%lld ",nw);
	}
	return 0;
}