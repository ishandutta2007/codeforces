#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1000005],b[1000005];
ll ans=0,suma,sumb;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),suma+=a[i];
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),sumb+=b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]>b[1])
	{
		printf("-1");
		return 0;
	}
	if(a[n]==b[1])
	{
		printf("%I64d",1ll*(suma-a[n])*m+sumb);
		return 0;
	}
	printf("%I64d",1ll*(suma-a[n])*m+sumb+(a[n]-a[n-1]));
	return 0;
}