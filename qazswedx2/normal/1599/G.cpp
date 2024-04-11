#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,id;
	pt(){}
	pt(int x,int y):x(x),y(y){}
}a[1000005];
bool operator<(const pt a,const pt b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
pt operator-(const pt a,const pt b)
{
	return pt(a.x-b.x,a.y-b.y);
}
ll Cross(const pt a,const pt b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
double F(int i,int j)
{
	return sqrt(1ll*(a[i].x-a[j].x)*(a[i].x-a[j].x)+1ll*(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
	if(n>3)
	{
		ll ans1=Cross(a[2]-a[1],a[3]-a[1]),ans2=Cross(a[4]-a[1],a[3]-a[1]);
		ll ans3=Cross(a[2]-a[1],a[4]-a[1]);
		if(ans1&&ans2&&ans3) swap(a[1],a[n]);
		else if(ans1&&ans3) swap(a[2],a[n]);
		else if(ans1&&ans2) swap(a[3],a[n]);
		else if(ans2&&ans3) swap(a[4],a[n]);
		else
		{
			for(int i=3;i<=n;i++)
				if(Cross(a[2]-a[1],a[i]-a[1]))
				{
					swap(a[i],a[n]);
					break;
				}
		}
	}
	sort(a+1,a+n);
	for(int i=1;i<=n;i++)
		if(a[i].id==k)
		{
			k=i;
			break;
		}
	double ans=1e18;
	if(k==n)
	{
		ans=min(ans,F(1,n-1)+min(F(1,n),F(n-1,n)));
		printf("%.10f\n",ans);
		return 0;
	}
	ans=min(ans,F(k,n)+F(1,n-1)+min(F(1,n),F(n-1,n)));
//	printf("ans=%.10f\n",ans);
	ans=min(ans,F(1,n-1)+min(F(1,n)+F(n-1,k),F(n-1,n)+F(1,k)));
//	printf("ans=%.10f\n",ans);
	ans=min(ans,F(k,1)+F(1,n)+(k==n-1?0:F(n,k+1)+F(k+1,n-1)));
	ans=min(ans,F(k,n-1)+F(n-1,n)+(k==1?0:F(n,k-1)+F(k-1,1)));
	for(int i=2;i<=k;i++)
		ans=min(ans,F(1,i-1)+min(F(i-1,n),F(1,n))+F(i,n)+F(i,n-1)+F(k,n-1));
//	printf("ans=%.10f\n",ans);
	for(int i=k;i<n-1;i++)
		ans=min(ans,F(k,1)+F(1,i)+F(i,n)+min(F(n,i+1),F(n,n-1))+F(i+1,n-1));
	printf("%.10f\n",ans);
	return 0;
}