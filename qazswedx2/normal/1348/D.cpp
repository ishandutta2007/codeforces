#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n;
bool check(int x)
{
	if(n-x-1<0||x>=35) return 1;
	ll nw=n-x-1;
	for(int i=1;i<=x;i++)
	{
		if(nw<=1ll*(1ll<<(ll)(i-1))*(x-i+1)) return 1;
		nw-=1ll*(1ll<<(ll)(i-1))*(x-i+1);
	}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int l=1,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
		n-=l+1;
		int sum=1;
		for(int i=1;i<=l;i++)
		{
			int v=l-i+1,nw;
			nw=n/v;
			if(i<=35&&nw>sum) nw=sum;
			n-=nw*v;
			sum+=nw;
			printf("%d ",nw);
		}
		printf("\n");
	}
	return 0;
}