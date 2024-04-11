#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=320001,MAX=300010;
int n,m,T; 
int a[N];
ll Tree[N][2];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void addi(int x,ll k,int t)
{
	for (;x<=MAX;x+=lowbit(x)) Tree[x][t]+=k;
}
inline ll ask(int x,int t)
{
	ll ans=0;
	if (x>MAX) x=MAX;
	for (;x;x-=lowbit(x)) ans+=Tree[x][t];
	return ans;
}
inline ll query(int x,int y,int t)
{
	return ask(y,t)-ask(x-1,t);
}

struct ST
{
	int l,r;
	ll sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[4*N];
void build(int u,int l,int r)
{
	if (l==r) 
	{
		l(u)=l,r(u)=r,sum(u)=0,add(u)=0;
		return;
	}
	int mid=(l+r)/2;
	l(u)=l,r(u)=r;
	add(u)=0;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	sum(u)=sum(u*2)+sum(u*2+1);
}
void spread(int u)
{
	if (add(u)!=0)
	{
		sum(u*2)+=add(u)*(r(u*2)-l(u*2)+1);
		sum(u*2+1)+=add(u)*(r(u*2+1)-l(u*2+1)+1);
		add(u*2)+=add(u);
		add(u*2+1)+=add(u);
		add(u)=0;
	}
}
void change(int u,int l,int r,ll k)
{
	if (l(u)>=l&&r(u)<=r)
	{
		add(u)+=k;
		sum(u)+=(r(u)-l(u)+1)*k;
		return;
	}
	spread(u);
	int mid=(l(u)+r(u))/2;
	if (l<=mid) change(u*2,l,r,k);
	if (mid<r) change(u*2+1,l,r,k);
	sum(u)=sum(u*2)+sum(u*2+1);
}
ll asksg(int u,int l,int r)
{
	if (l(u)>=l&&r(u)<=r)
	{
		return sum(u);
	}
	spread(u);
	int mid=(l(u)+r(u))/2;
	ll res=0;
	if (l<=mid) res+=asksg(u*2,l,r);
	if (mid<r) res+=asksg(u*2+1,l,r);
	return res;
}

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

ll ans[N];

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	ans[1]=0;
	addi(a[1],1,0);
	addi(a[1],a[1],1);
	build(1,1,MAX);
	for (int j=1;a[1]*j<=MAX;j++)
	{
		int u=a[1]*j,v=a[1]*(j+1);
		change(1,u,min(v-1,MAX),a[1]*j);
	}
	for (int i=2;i<=n;i++)
	{
		ans[i]=ans[i-1];
		ans[i]+=(i-1-ask(a[i],0))*a[i];
		ans[i]+=ask(a[i],1);
		ans[i]+=a[i]*ask(a[i],0);
		//cout << ans[i] << endl;
		ans[i]-=asksg(1,a[i],a[i]);
		//cout << ans[i] << endl;
		for (int j=1;a[i]*j<=MAX;j++)
		{
			int u=a[i]*j,v=a[i]*(j+1);
			ans[i]+=query(u,v-1,1)-query(u,v-1,0)*j*a[i];
			change(1,u,min(v-1,MAX),a[i]*j);
		}
		addi(a[i],1,0);
		addi(a[i],a[i],1);
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}