#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a,d,t[100001],k,k1,ans,r,k2,k3;
bool cmp(long long aa,long long bb){return(aa<bb);}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&a,&d);
	for(int i=1;i<=m;i++)scanf("%I64d",&t[i]);
	sort(t+1,t+1+m,cmp);
	k=d/a;
	k++;
	r=0;
	for(int i=1;i<=m;i++)
	{
		if(t[i]<=r) continue;
		k1=r/a;
		k1++;
		k2=t[i]/a;
		if(k1>n)
		{
			ans++;
			r=t[i]+d;
			continue;
		}
		if(k2>n) k2=n;
		if(k2<k1)
		{
			ans++;
			r=t[i]+d;
		}
		else
		{
			k3=(k2-k1+1)/k;
			ans=ans+k3;
			if((k2-k1+1)%k!=0) ans=ans+1;
			else k3--;
			if(k*a*k3+k1*a+d>=t[i])
			{
				r=k*a*k3+k1*a+d;
			}
			else
			{
				ans++;
				r=t[i]+d;
			}
		}
	}
	if(r<n*a)
	{
		k1=r/a;
		k1++;
		ans=ans+(n-k1+1)/k;
		if((n-k1+1)%k!=0) ans++;
	}
	printf("%I64d\n",ans);
}