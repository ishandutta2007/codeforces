#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=1000010;
LL mx[N],mn[N],a[N],ans;
int mxb[N],mnb[N],bit[N],cnt[100],n;
void work(int l,int r)
{
	if(l==r){ans++;return;}
	int mid=(l+r)>>1;
	mx[mid]=mn[mid]=a[mid];mxb[mid]=mnb[mid]=bit[mid];
	mx[mid+1]=mn[mid+1]=a[mid+1];mxb[mid+1]=mnb[mid+1]=bit[mid+1];
	for(int i=mid-1;i>=l;i--)mx[i]=max(mx[i+1],a[i]),mn[i]=min(mn[i+1],a[i]),mxb[i]=mx[i]==a[i]?bit[i]:mxb[i+1],mnb[i]=mn[i]==a[i]?bit[i]:mnb[i+1];
	for(int i=mid+2;i<=r;i++)mx[i]=max(mx[i-1],a[i]),mn[i]=min(mn[i-1],a[i]),mxb[i]=mx[i]==a[i]?bit[i]:mxb[i-1],mnb[i]=mn[i]==a[i]?bit[i]:mnb[i-1];
	int now=mid;
	for(int i=mid;i>=l;i--)if(mxb[i]==mnb[i])
	{
		for(;now<r&&mx[now+1]<=mx[i]&&mn[now+1]>=mn[i];now++);
		ans+=now-mid;
	}
	now=mid+1;
	for(int i=mid+1;i<=r;i++)if(mxb[i]==mnb[i])
	{
		for(;now>l&&mx[now-1]<mx[i]&&mn[now-1]>mn[i];now--);
		ans+=mid+1-now;
	}
	rep(i,60)cnt[i-1]=0;
	now=mid;
	int now2=mid+1;
	for(int i=mid;i>=l;i--)
	{
		for(;now<r&&mx[now+1]<=mx[i];cnt[mnb[++now]]++);
		for(;now2<=now&&mn[now2]>=mn[i];cnt[mnb[now2++]]--);
		ans+=cnt[mxb[i]];
	}
	rep(i,60)cnt[i-1]=0;
	now=mid+1;
	now2=mid;
	for(int i=mid+1;i<=r;i++)
	{
		for(;now>l&&mx[now-1]<mx[i];cnt[mnb[--now]]++);
		for(;now2>=now&&mn[now2]>mn[i];cnt[mnb[now2--]]--);
		ans+=cnt[mxb[i]];
	}
	work(l,mid);
	work(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&a[i]),bit[i]=__builtin_popcountll(a[i]);
	work(1,n);
	printf("%lld\n",ans);
    return 0;
}