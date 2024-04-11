#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,id,fl;
	pt(int l=0,int r=0,int id=0,int fl=0):l(l),r(r),id(id),fl(fl){}
	bool operator<(const pt x) const
	{
		return r<x.r;
	}
}q[1000005];
int n,m,p[200005],a[200005],b[200005],qt,st[200005],tp;
ll qans[200005],sum[200005],f[200005];
set<int> s;
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,ll v)
{
//	printf("modify:x=%d,v=%lld\n",x,v);
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=v;
}
ll query(int x)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	n++;
	p[n]=n;
	q[++qt]=pt(1,n,0,1);
	s.insert(1);
	s.insert(n);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1) continue;
		set<int>::iterator it;
		if(s.find(x)!=s.end())
		{
			s.erase(x);
			it=s.upper_bound(x);
			int v=*it;
			q[++qt]=pt(x,v,i,-1);
			it--;
			q[++qt]=pt(*it,x,i,-1);
			q[++qt]=pt(*it,v,i,1);
		}
		else
		{
			it=s.upper_bound(x);
			int v=*it;
			q[++qt]=pt(x,v,i,1);
			it--;
			q[++qt]=pt(*it,x,i,1);
			q[++qt]=pt(*it,v,i,-1);
			s.insert(x);
		}
	}
	sort(q+1,q+qt+1);
	int qnw=1;
	while(qnw<=qt&&q[qnw].r==1) qnw++;
//	for(int i=1;i<=qt;i++)
//		printf("i=%d,l=%d,r=%d,id=%d,fl=%d\n",i,q[i].l,q[i].r,q[i].id,q[i].fl);
	st[1]=1,tp=1;
	for(int i=2;i<=n;i++)
	{
		ll las=a[i-1],sum=0;
	//	printf("i=%d\n",i);
		while(tp&&p[st[tp]]<p[i])
		{
			ll nw=min(las,(ll)b[st[tp]]);
		//	printf("st=%d,las=%lld,nw=%lld,sum=%lld,f=%lld\n",st[tp],las,nw,sum,f[tp]);
			modify(st[tp-1]+1,nw-sum);
			modify(st[tp]+1,-nw+sum);
			las=nw+f[tp];
			sum+=f[tp];
			tp--;
		}
		modify(1,las-sum);
		modify(st[tp]+1,-las+sum);
		st[++tp]=i;
		f[tp]=las;
		while(qnw<=qt&&q[qnw].r==i)
		{
			qans[q[qnw].id]+=query(q[qnw].l)*q[qnw].fl;
			qnw++;
		}
	}
	for(int i=1;i<=m;i++)
		qans[i]+=qans[i-1];
	for(int i=1;i<=m;i++)
		printf("%lld\n",qans[i]);
	return 0;
}