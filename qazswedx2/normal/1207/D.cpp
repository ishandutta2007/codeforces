#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
}a[1000005];
int n,cnt1[1000005],cnt2[1000005],fr[1000005];
const int mod=998244353;
bool cmp3(const pt xx,const pt yy)
{
	return xx.x==yy.x?xx.y<yy.y:xx.x<yy.x;
}
int main()
{
	scanf("%d",&n);
	fr[0]=1;
	for(int i=1;i<=n;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		cnt1[a[i].x]++;
		cnt2[a[i].y]++;
	}
	int mul1=1,mul2=1;
	for(int i=1;i<=n;i++)
		if(cnt1[i])
			mul1=1ll*mul1*fr[cnt1[i]]%mod;
	for(int i=1;i<=n;i++)
		if(cnt2[i])
			mul2=1ll*mul2*fr[cnt2[i]]%mod;
	sort(a+1,a+n+1,cmp3);
	int fl=1;
	for(int i=2;i<=n;i++)
		if(a[i].x<a[i-1].x||a[i].y<a[i-1].y)
			fl=0;
	int mul3=0;
	if(fl)
	{
		mul3=1;
		int sum=1,valx=a[1].x,valy=a[1].y;
		for(int i=2;i<=n;i++)
		{
			if(valx==a[i].x&&valy==a[i].y) sum++;
			else
			{
				mul3=1ll*mul3*fr[sum]%mod;
				sum=1;
				valx=a[i].x;
				valy=a[i].y;
			}
		}
		mul3=1ll*mul3*fr[sum]%mod;
	}
	int ans=fr[n];
	ans=((1ll*ans-mul1-mul2+mul3)%mod+mod)%mod;
	//printf("mul=%d,%d,%d\n",mul1,mul2,mul3);
	printf("%d",ans);
	return 0;
}