#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,tans[15];
int cnt[105];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	if(m<n||(m-n)%2)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<=62;i++)
		if((1ll<<i)&n)	
			cnt[i]++;
	m-=n;
	for(int i=1;i<=62;i++)
		if((1ll<<i)&m)
			cnt[i-1]+=2;
	int mx=0;
	for(int i=0;i<=62;i++)
		mx=max(mx,cnt[i]);
	printf("%d\n",mx);
	for(int i=1;i<=mx;i++)
	{
		ll nw=0;
		for(int j=0;j<=62;j++)
			if(cnt[j]>=i)
				nw|=(1ll<<j);
		printf("%I64d ",nw);
	}
	return 0;
}