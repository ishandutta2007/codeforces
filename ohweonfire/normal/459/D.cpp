#include <cstdio>
#include <map>
using namespace std;
typedef long long LL;
const int maxn=1000005;
int bit[maxn],n,a[maxn],b[maxn],dat[maxn];
void add(int id,int val)
{
	for(;id<=n;id+=id&-id)
		bit[id]+=val;
}
int sum(int id)
{
	int ret=0;
	for(;id;id-=id&-id)
		ret+=bit[id];
	return ret;
}
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",dat+i);
		mp[dat[i]]++;
		a[i]=mp[dat[i]];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=mp[dat[i]];
		mp[dat[i]]--;
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=i-1-sum(b[i]);
		add(a[i],1);
	}
	printf("%I64d\n",ans);
	return 0;
}