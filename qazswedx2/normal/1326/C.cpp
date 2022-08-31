#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int n,m,a[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	ll sum=0;
	int ans=1,las=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=n-m+1)
		{
			sum+=a[i];
			if(las) ans=1ll*(i-las)*ans%mod;
			las=i;
		}
	}
	printf("%I64d %d",sum,ans);
	return 0;
}