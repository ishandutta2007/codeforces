#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
int sgn(int x)
{
	if(x>0) return 1;
	if(x==0) return 0;
	return -1;
}
struct pt
{
	int x,y,fl1,fl2;
	pt(int x=0,int y=0):x(x),y(y){fl1=sgn(x);fl2=sgn(y);}
}a[1000005];
ll F(pt a,pt b)
{
	return 1ll*a.x*b.x+1ll*a.y*b.y;
}
ll G(pt a,pt b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool operator<(const pt a,const pt b)
{
	if(a.fl1!=b.fl1) return a.fl1<b.fl1;
	if(a.fl2!=b.fl2) return a.fl2<b.fl2;
	return G(a,b)<0;
}
map<pt,int> mp;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y,xx,yy;
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			a[i]=pt(x-xx,y-yy);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=mp[a[i]];
		//	printf("i=%d,mp=%d\n",i,mp[a[i]]);
			mp[pt(-a[i].x,-a[i].y)]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}