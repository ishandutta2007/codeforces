#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,t;
ll ans=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int x=(n-m)/(m+1),b=(n-m)%(m+1),s=m+1-b;
		ans=1ll*x*(x+1)/2*s;
		ans+=1ll*(x+1)*(x+2)/2*b;
		ans=1ll*n*(n+1)/2-ans;
		printf("%I64d\n",ans);
	}
	return 0;
}