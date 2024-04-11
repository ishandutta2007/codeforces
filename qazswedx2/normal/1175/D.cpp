#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1000005];
ll b[1000005],ans=0;
bool cmp(const ll x,const ll y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>0;i--)
		b[i]=b[i+1]+a[i];
	ans+=b[1];
	sort(b+2,b+n+1,cmp);
	for(int i=2;i<=m+1;i++)
		ans+=b[i];
	printf("%I64d\n",ans);
	return 0;
}