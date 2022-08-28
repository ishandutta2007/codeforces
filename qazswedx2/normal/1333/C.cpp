#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,int> mp;
int n;
ll a[1000005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	mp[0]=0;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(mp.count(a[i])) l=max(l,mp[a[i]]+2);
		if(l<=i) ans+=(i-l+1);
		mp[a[i]]=i;
	}
	printf("%I64d",ans);
	return 0;
}