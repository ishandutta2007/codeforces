#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int b,p;};
node d[100011],e[100011];
int n,m,cnt,now[100001],now1[100001],lazy[400001],l[400001],r[400001],size[400001];
long long s[400001],sum,a[100001],c[100001],dbd,maxnum;
bool cmp(node aa,node bb){return(aa.b<bb.b);}
int ask(int l,int r)
{
	if(l==r) return(l);
	int mid=(l+r+1)/2;
	if(d[mid].b<=dbd) l=mid;
	else r=mid-1;
	return(ask(l,r));
}

void update(int num)
{
	lazy[num]=0;
	size[num]=0;
	s[num]=0;
}

void built(int num,int x,int y)
{
	l[num]=x;
	r[num]=y;
	s[num]=0;
	lazy[num]=-1;
	size[num]=0;
	if(x==y) return;
	int mid=(x+y)/2;
	built(num*2,x,mid);
	built(num*2+1,mid+1,y);
}

int ask1(int num,long long ss)
{
	if((l[num]==r[num])) return(l[num]);
	if(lazy[num]==0)
	{
		update(num*2);
		update(num*2+1);
		lazy[num]=-1;
	}
	long long anss;
	if(s[num*2]+ss<=sum) anss=ask1(num*2+1,ss+s[num*2]);
	else anss=ask1(num*2,ss);
	size[num]=size[num*2]+size[num*2+1];
	s[num]=s[num*2]+s[num*2+1];
	return(anss);
}

void cl(int num,int x)
{
	if(x==l[num])
	{
		update(num);
		return;
	}
	int mid=(l[num]+r[num])/2;
	if(lazy[num]==0)
	{
		update(num*2);
		update(num*2+1);
		lazy[num]=-1;
	}
	if(x<=mid)
	{
		cl(num*2,x);
		cl(num*2+1,mid+1);
	}
	else cl(num*2+1,x);
	size[num]=size[num*2]+size[num*2+1];
	s[num]=s[num*2]+s[num*2+1];
}

void gai(int num,int x)
{
	if(l[num]==r[num])
	{
		s[num]=dbd;
		size[num]=1;
		return;
	}
	int mid=(l[num]+r[num])/2;
	if(lazy[num]==0)
	{
		update(num*2);
		update(num*2+1);
		lazy[num]=-1;
	}
	if(x<=mid) gai(num*2,x);
	else gai(num*2+1,x);
	size[num]=size[num*2]+size[num*2+1];
	s[num]=s[num*2]+s[num*2+1];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	c[0]=0;
	cnt=0;
	for(int i=n;i>=1;i--) if(a[i]>=c[cnt])
	{
		cnt++;
		c[cnt]=a[i];
		now[i]=cnt;
	}
	d[0].b=0;
	for(int i=1;i<=m;i++) scanf("%d",&d[i].b);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d",&d[i].p);
		e[i].b=d[i].p;
		e[i].p=i;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++) d[e[i].p].p=i;
	sort(d+1,d+1+m,cmp);
	built(1,1,m);
	for(int i=0;i<=cnt;i++) 
	{
		dbd=c[i];
		now1[i]=ask(0,m);
	}
	for(int i=1;i<=n;i++) 
	{
		sum=sum+a[i];
		if(now[i]!=0)
		{
			int k1=now[i],k2;
			k2=k1-1;
			for(int j=now1[k2]+1;j<=now1[k1];j++) 
			{
				dbd=e[d[j].p].b;
				gai(1,d[j].p);
			}
			if(s[1]>sum)
			{
				dbd=ask1(1,0);
				cl(1,dbd);
			}
		}
	}
	printf("%d\n",size[1]);
}