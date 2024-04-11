#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,t,fl;
	pt(int x=0,int t=0,int fl=0):x(x),t(t),fl(fl){}
	bool operator<(const pt p) const
	{
		if(x!=p.x) return x<p.x;
		if(fl!=p.fl) return fl<p.fl;
		return t<p.t;
	}
};
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
ll ans=0;
pt c[1000005],tmp[1000005];
void solve(int n,int m,int v,vector<pt> a)
{
	if(a.empty())
	{
		ans=1e18;
		return;
	}
	int len=a.size(),inv,qwq;
	exgcd(m,n,inv,qwq);
	inv=(inv%n+n)%n;
	for(int i=0;i<len;i++)
		a[i].x=1ll*a[i].x*inv%n;
	sort(a.begin(),a.end());
	/*printf("solve:n=%d,m=%d,v=%d,a=",n,m,v);
	for(int i=0;i<(int)a.size();i++)
		printf("(%d,%d) ",a[i].x,a[i].t);
	printf("\n");*/
	int tt=0;
	for(int l=0,r;l<len;l=r+1)
	{
		r=l;
		while(r<len-1&&a[r+1].x==a[l].x) r++;
		tmp[tt++]=a[l];
	}
	int mn=2e9,id=-1;
	for(int i=0;i<tt;i++)
		if(tmp[i].t<mn) mn=tmp[i].t,id=i;
	for(int i=0;i<tt;i++)
		c[i]=tmp[(i+id)%tt];
/*	printf("c=");
	for(int i=0;i<tt;i++)
		printf("(%d,%d) ",c[i].x,c[i].t);
	printf("\n");*/
	for(int i=0;i<tt;i++)
	{
		int len=(c[(i+1)%tt].x-c[i].x+n)%n;
		if(!len) len=n;
		if(c[i].fl||len>1) ans=max(ans,1ll*(len-1)*v+c[i].t);
		if(i+1<tt) c[i+1].t=min((ll)c[i+1].t,c[i].t+1ll*len*v);
	}
}
int n,m,g,a[200005],at,b[200005],bt;
vector<pt> val[200005],val2[200005];
int main()
{
	scanf("%d%d",&n,&m);
	g=gcd(n,m);
	scanf("%d",&at);
	for(int i=1;i<=at;i++)
		scanf("%d",&a[i]);
	scanf("%d",&bt);
	for(int i=1;i<=bt;i++)
		scanf("%d",&b[i]);
	if(g>at+bt)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=at;i++)
		val[a[i]%g].push_back(pt(a[i]/g,a[i],0));
	for(int i=1;i<=bt;i++)
	{
		int u=b[i]%n;
		val[u%g].push_back(pt(u/g,b[i],1));
	}
	for(int i=0;i<g;i++)
		solve(n/g,m/g,m,val[i]);
	for(int i=1;i<=bt;i++)
		val2[b[i]%g].push_back(pt(b[i]/g,b[i],0));
	for(int i=1;i<=at;i++)
	{
		int u=a[i]%m;
		val2[u%g].push_back(pt(u/g,a[i],1));
	}
	for(int i=0;i<g;i++)
		solve(m/g,n/g,n,val2[i]);
	if(ans<1e18) printf("%lld\n",ans);
	else printf("-1\n");
	return 0;
}