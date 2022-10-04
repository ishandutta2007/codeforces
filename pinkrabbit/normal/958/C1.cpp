#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long Max(long long a,long long b){return a>b?a:b;}
long long n,p,ans,a[100005],sumq,suml;
int main()
{
	scanf("%I64d%I64d",&n,&p);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]) ,suml+=1ll*a[i];
	for(int i=1;i<n;i++)
	{
		suml-=1ll*a[i];sumq+=1ll*a[i];
		ans=Max(ans,1ll*suml%p+sumq%p);
	}
	printf("%I64d",ans);
	return 0;
}