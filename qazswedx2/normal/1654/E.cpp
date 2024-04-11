#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
#include<ctime>
#include<unordered_map>
using namespace std;
typedef unsigned long long ull;
typedef long long 
ll;
int n,a[1000005],sn=230,B,buf[50000005],*vis=buf+25000000,ans2;
ull x;
mt19937_64 rnd(time(0));
unordered_map<ull,int> mp;
void ins(ll p)
{
	ans2=max(ans2,++mp[p^x]);
}
int main()
{
	rnd(),rnd(),rnd();
	x=rnd();
	scanf("%d",&n);
//	while(1ll*(sn+1)*(sn+1)<=n) sn++;
	for(int i=1;i<=n;i++)	
		scanf("%d",&a[i]);
	B=1e5/sn+3;
	int ans=0;
	for(int i=-sn;i<=sn;i++)
	{
		for(int j=1;j<=n;j++)
			ans=max(ans,++vis[a[j]-j*i]);
		for(int j=1;j<=n;j++)
			vis[a[j]-j*i]--;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=min(i+B,n);j++)
			if((a[j]-a[i])%(j-i)==0)
			{
				int k=(a[j]-a[i])/(j-i);
				ll b=a[i]-1ll*k*i;
			//	printf("k=%d,b=%lld\n",k,b);
				ins(k+b*300005);
			}
	int t=0;
	while(1ll*(t+1)*t/2<=ans2) t++;
	ans=max(ans,t);
	printf("%d\n",n-ans);
	return 0;
}