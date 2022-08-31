#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t,n,k,ans;
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		ans=0;
		scanf("%I64d%I64d",&n,&k);
		while(n)
		{
			ans=ans+n%k;
			n=n-n%k;
			if(!n) break;
			n/=k;
			ans++;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}