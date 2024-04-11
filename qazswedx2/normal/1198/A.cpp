#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[1000005],b[1000005],bt,cnt[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	m=((m*8)/n);
	if(m>=30)
	{
		printf("0");
		return 0;
	}
	m=(1<<m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[++bt]=a[i];
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
		cnt[lower_bound(b+1,b+bt+1,a[i])-b]++;
	//for(int i=1;i<=bt;i++)
	//	printf("%d ",cnt[i]);
	//printf("\n");
	//printf("m=%d\n",m);
	if(bt<=m)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=bt;i++)
		cnt[i]+=cnt[i-1];
	int ans=1e9;
	for(int i=0;i<=bt-m;i++)
	{
		int j=bt-(bt-m-i);
		//printf("i=%d,j=%d,%d\n",i,j,cnt[i]+(cnt[bt]-cnt[j]));
		ans=min(ans,cnt[i]+(cnt[bt]-cnt[j]));
	}
	printf("%d",ans);
	return 0;
}