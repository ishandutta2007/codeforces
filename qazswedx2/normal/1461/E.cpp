#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll k,l,r,t,x,y,a[1000005];
int vis[1000005];
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);
	if(x>=y)
	{
		if(k+y<=r) k+=y;
		if(x==y)
		{
			if(k-x>=l) printf("Yes\n");
			else printf("No\n");
			return 0;
		}
		if(t<=(k-l-y)/(x-y)) printf("Yes\n");
		else printf("No\n");
		return 0;
	}
	r-=y;
	if(r-l+1>=x)
	{
		printf("Yes\n");
		return 0;
	}
	if(l>r)
	{
		if((k-l)/x+1<=t)
			printf("No\n");
		else printf("Yes\n");
		return 0;
	}
	for(ll i=r%x,j=r;j>r-x;j--,i=(i+x-1)%x)
		a[i]=j;
	ll ans=0;
	while(1)
	{
		ans+=(k-a[k%x])/x;
		if(ans>1.5e18) ans=1.5e18;
		if(a[k%x]<l) break;
		if(vis[k%x]==1)
		{
			printf("Yes\n");
			return 0;
		}
		vis[k%x]=1;
		k=a[k%x]+y;
	}
	if(ans<=t) printf("No\n");
	else printf("Yes\n");
	return 0;
}