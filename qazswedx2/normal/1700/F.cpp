#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005][2],b[1000005][2];
inline int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][1]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i][1]);
	int x=0,y=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		x+=a[i][0]-b[i][0];
		y+=a[i][1]-b[i][1];
		if(x<0&&y>0) x++,y--,ans++;
		if(x>0&&y<0) x--,y++,ans++;
		ans+=F(x+y);
	}
	if(x||y) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}