#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int cnt[2],v[2];
bool check(LL val)
{
	LL f[]={val/v[0],val/v[1]},l=v[0]*1ll*v[1],both=val/l,other=val-f[0]-f[1]+both;
	f[0]-=both;
	f[1]-=both;
	LL tcnt[]={cnt[0]-f[1],cnt[1]-f[0]};
	return max(0ll,tcnt[0])+max(0ll,tcnt[1])<=other;
}
int main()
{
	scanf("%d%d%d%d",cnt,cnt+1,v,v+1);
	LL l=0,r=1ll<<62;
	while(l<r-1)
	{
		LL mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%I64d\n",r);
	return 0;
}