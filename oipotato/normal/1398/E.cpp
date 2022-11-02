#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=200010;
int num[N<<2],fi[N<<2],n,tp[N],d[N],a[N],lt;
long long sum[N<<2],all;
void modify(int p,int le,int ri,int x,int tp,int c,int d)
{
	num[p]+=c;
	if(!tp)fi[p]+=c;
	sum[p]+=d;
	if(le==ri)return;
	int mid=(le+ri)>>1;
	if(x<=mid)modify(p<<1,le,mid,x,tp,c,d);
	else modify(p<<1|1,mid+1,ri,x,tp,c,d);
}
pair<long long,int> add(pair<long long,int>x,pair<long long,int>y){return mp(x.first+y.first,x.second+y.second);}
pair<long long,int> get(int p,int le,int ri,int k)
{
	if(!k)return mp(0,0);
	if(le==ri)return mp(sum[p],fi[p]);
	int mid=(le+ri)>>1;
	if(num[p<<1]>=k)return get(p<<1,le,mid,k);
	else return add(mp(sum[p<<1],fi[p<<1]),get(p<<1|1,mid+1,ri,k-num[p<<1]));
}
set<int>s;
int main()
{
	scanf("%d",&n);
	int cnt=0;
	rep(i,n)
	{
		scanf("%d%d",&tp[i],&d[i]);
		if(d[i]>0)a[++cnt]=d[i];
	}
	sort(a+1,a+cnt+1);
	rep(i,n)
	{
		all+=d[i];
		lt+=(d[i]>0?1:-1)*tp[i];
		modify(1,1,cnt,cnt-(lower_bound(a+1,a+cnt+1,abs(d[i]))-a)+1,tp[i],d[i]>0?1:-1,d[i]);
		if(!tp[i]){if(d[i]>0)s.insert(d[i]);else s.erase(-d[i]);}
		if(!lt)printf("%lld\n",all);
		else
		{
			auto tmp=get(1,1,cnt,lt);
			if(tmp.second)printf("%lld\n",all+tmp.first);
			else printf("%lld\n",all+get(1,1,cnt,lt-1).first+(!s.empty()?*s.rbegin():0));
		}
	}
    return 0;
}