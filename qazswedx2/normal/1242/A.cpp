#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,tn;
int main()
{
	scanf("%I64d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	tn=n;
	int cnt=0;
	ll nw=0;
	for(int i=2;1ll*i*i<=n;i++)
		if(n%i==0)
		{
			cnt++;
			nw=i;
			while(n%i==0) n/=i;
		}
	if(n>1)
	{
		cnt++;
		nw=n;
	}
	if(cnt>=2) printf("1");
	else printf("%I64d",nw);
	return 0;
}