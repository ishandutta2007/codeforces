#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1002;
ll row[maxn],col[maxn],tmp;
int n,m,x,y;
ll d(int &x,int &i)
{
	return (((i-x)*4-2ll)*((i-x)*4-2ll));
}
ll c1(int x)
{
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=row[i]*d(x,i);
	return ans;
}
ll c2(int x)
{
	ll ans=0;
	for(int i=1;i<=m;i++)
		ans+=col[i]*d(x,i);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			row[i]+=x;
			col[j]+=x;
		}
	x=0;
	y=0;
	ll a=c1(x),b=c2(y);
	for(int i=1;i<=n;i++)
	{
		tmp=c1(i);
		if(tmp<a)
		{
			a=tmp;
			x=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		tmp=c2(i);
		if(tmp<b)
		{
			b=tmp;
			y=i;
		}
	}
	printf("%I64d\n",a+b);
	printf("%d %d\n",x,y);
	return 0;
}