#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct pt
{
	int id;
	ll val;
	pt(int id=0,ll val=0):id(id),val(val){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
};
int n,m,a[100005],b[100005];
ll ans;
priority_queue<pt> pq;
ll F(int x,int y)
{
	ll p=x%y,q=x/y;
	return p*(q+1)*(q+1)+(y-p)*q*q;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=1ll*a[i]*a[i];
		b[i]=1;
		if(a[i]>1) pq.push(pt(i,F(a[i],1)-F(a[i],2)));
	}
	m-=n;
	for(int i=1;i<=m;i++)
	{
		pt u=pq.top();
		pq.pop();
		ans-=u.val;
		b[u.id]++;
		if(a[u.id]>b[u.id]) pq.push(pt(u.id,F(a[u.id],b[u.id])-F(a[u.id],b[u.id]+1)));
	}
	printf("%lld\n",ans);
	return 0;
}