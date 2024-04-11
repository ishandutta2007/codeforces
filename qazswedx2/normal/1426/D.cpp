#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int n,f[1000005];
ll a[1000005];
map<ll,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int las=0,ct=0;
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		int l;
		if(mp.count(a[i])) l=mp[a[i]]+1;
		else
		{
			mp[a[i]]=i;continue;
		}
		//printf("l=%d,i=%d,a=%lld,las=%d\n",l,i,a[i],las);
		if(las<l) las=i-1,ct++;
		mp[a[i]]=i;
	}
	printf("%d\n",ct);
	return 0;
}