#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct pt
{
	int val,id;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}a[500005];
int n;
ll ans;
priority_queue<pt> pq;
bool cmp(const pt x,const pt y)
{
	return x.id<y.id;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].id);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].val);
	sort(a+1,a+n+1,cmp);
	int nw=1;
	for(int i=1;;i++)
	{
		if(pq.empty())
		{
			if(nw>n) break;
			i=a[nw].id;
		}
		while(nw<=n&&a[nw].id==i)
		{
			pq.push(a[nw]);
			nw++;
		}
		//printf("i=%d,nw=%d,size=%d\n",i,nw,pq.size());
		pt u=pq.top();
		pq.pop();
		ans+=1ll*(i-u.id)*u.val;
	}
	printf("%I64d",ans);
	return 0;
}