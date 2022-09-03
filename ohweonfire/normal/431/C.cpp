#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef long long ll;
const int maxn=102;
const ll mod=1000000007;
ll tmp[maxn];
ll calc (int n,int k)
{
 	memset(tmp,0,sizeof(tmp));
 	tmp[0]=1;
 	ll sum=0;
 	for(int i=1;i<=n;i++)
 	{
	 		if(i<=k)
	 		tmp[i]=sum+1,sum=(sum+tmp[i])%mod;
	 		else tmp[i]=sum,sum=(sum+tmp[i]-tmp[i-k])%mod;
	}
	return tmp[n];
}
int main()
{
 	int n,k,d;
 	scanf("%d%d%d",&n,&k,&d);
 	ll ans=(calc(n,k)-calc(n,d-1))%mod;
 	while(ans<0)ans+=mod;
 	printf("%I64d\n",ans);
 	//system("pause");
 	return 0;
}