#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,c1,c2,c3,c4,c5,c6;
ll x,y;
void upd(int x,int &y,int z)
{
	y=min(y,x+z);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ll ans;
		scanf("%lld%lld",&x,&y);
		scanf("%d%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5,&c6);
		upd(c1,c2,c3);
		upd(c2,c3,c4);
		upd(c3,c4,c5);
		upd(c4,c5,c6);
		upd(c5,c6,c1);
		upd(c6,c1,c2);
		if(x<=0&&y>=0)
			ans=-x*c3+y*c2;
		else if(x>=0&&y<=0)
			ans=x*c6-y*c5;
		else if(x>=0&&y>=0)
		{
			if(x>=y) ans=(x-y)*c6+y*c1;
			else ans=(y-x)*c2+x*c1;
		}
		else
		{
			if(x<=y) ans=(y-x)*c3-y*c4;
			else ans=(x-y)*c5-x*c4;
		}
		printf("%lld\n",ans);
	}
	return 0;
}