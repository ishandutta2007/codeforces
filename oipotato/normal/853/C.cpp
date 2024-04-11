#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data
{
	int id,type,d,u,pos;
	friend bool operator <(data a,data b)
	{
		if(a.pos!=b.pos)
			return a.pos<b.pos;
		else if(a.type!=b.type)
			return a.type<b.type;
		else
			return a.id<b.id;
	}
}p[600010];
struct query
{
	int id,l,r,d,u;
}q[200010];
int c[200010],ansp[200010][10],a[200010],b[200010],tot,n,Q;
long long cal(int a[])
{
	long long ans=0;
	ans+=1ll*a[0]*(a[4]+a[5]+a[7]+a[8]);
	ans+=1ll*a[1]*(n-a[0]-a[1]-a[2]);
	ans+=1ll*a[2]*(a[3]+a[4]+a[6]+a[7]);
	ans+=1ll*a[3]*(n-a[0]-a[3]-a[6]);
	ans+=1ll*a[4]*(n-1);
	ans+=1ll*a[5]*(n-a[2]-a[5]-a[8]);
	ans+=1ll*a[6]*(a[1]+a[2]+a[4]+a[5]);
	ans+=1ll*a[7]*(n-a[6]-a[7]-a[8]);
	ans+=1ll*a[8]*(a[0]+a[1]+a[3]+a[4]);
	return ans/2;
}
inline int lowbit(int x){return x&(-x);}
void add(int x){for(;x<=n;x+=lowbit(x))c[x]++;}
int get(int x){int s=0;for(;x;x-=lowbit(x))s+=c[x];return s;}
bool cmp1(query a,query b)
{
	return a.l<b.l;
}
bool cmp2(query a,query b)
{
	return a.r>b.r;
}
bool cmp3(query a,query b)
{
	return a.d<b.d;
}
bool cmp4(query a,query b)
{
	return a.u>b.u;
}
bool cmp5(query a,query b)
{
	return a.id<b.id;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=i;
		p[i].type=0;
		p[i].id=i;
		p[i].pos=i;
		p[i].d=p[i].u=a[i];
	}
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d%d%d",&q[i].l,&q[i].d,&q[i].r,&q[i].u);
		q[i].id=i;
		p[n+i*2-1].type=1;
		p[n+i*2-1].id=i;
		p[n+i*2-1].pos=q[i].l-1;
		p[n+i*2-1].d=q[i].d;
		p[n+i*2-1].u=q[i].u;
		p[n+i*2].type=2;
		p[n+i*2].id=i;
		p[n+i*2].pos=q[i].r;
		p[n+i*2].d=q[i].d;
		p[n+i*2].u=q[i].u;
	}
	memset(c,0,sizeof(c));
	sort(p+1,p+n+2*Q+1);
	for(int i=1;i<=n+2*Q;i++)
		if(p[i].type==0)
			add(p[i].u);
		else if(p[i].type==1)
			ansp[p[i].id][4]-=get(p[i].u)-get(p[i].d-1);
		else
			ansp[p[i].id][4]+=get(p[i].u)-get(p[i].d-1);
	memset(c,0,sizeof(c));
	sort(q+1,q+Q+1,cmp1);
	int nowl=1;
	for(int i=1;i<=Q;i++)
	{
		for(;nowl<q[i].l;)
		{
			add(a[nowl]);
			nowl++;
		}
		ansp[q[i].id][0]=get(q[i].d-1);
		ansp[q[i].id][1]=get(q[i].u)-get(q[i].d-1);
		ansp[q[i].id][2]=get(n)-get(q[i].u);
	}
	memset(c,0,sizeof(c));
	sort(q+1,q+Q+1,cmp2);
	int nowr=n;
	for(int i=1;i<=Q;i++)
	{
		for(;nowr>q[i].r;)
		{
			add(a[nowr]);
			nowr--;
		}
		ansp[q[i].id][6]=get(q[i].d-1);
		ansp[q[i].id][7]=get(q[i].u)-get(q[i].d-1);
		ansp[q[i].id][8]=get(n)-get(q[i].u);
	}
	memset(c,0,sizeof(c));
	sort(q+1,q+Q+1,cmp3);
	int nowd=1;
	for(int i=1;i<=Q;i++)
	{
		for(;nowd<q[i].d;)
		{
			add(b[nowd]);
			nowd++;
		}
		ansp[q[i].id][3]=get(q[i].r)-get(q[i].l-1);
	}
	memset(c,0,sizeof(c));
	sort(q+1,q+Q+1,cmp4);
	int nowu=n;
	for(int i=1;i<=Q;i++)
	{
		for(;nowu>q[i].u;)
		{
			add(b[nowu]);
			nowu--;
		}
		ansp[q[i].id][5]=get(q[i].r)-get(q[i].l-1);
	}
	sort(q+1,q+Q+1,cmp5);
	for(int i=1;i<=Q;i++)
		printf("%I64d\n",cal(ansp[i]));
	return 0;
}