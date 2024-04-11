#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const double pi=acos(-1);

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
struct bit
{
	int n,t[N*2];
	void send(int _n){n=_n,memset(t,0,sizeof(t));}
	void add(int x){for (;x<=n;x+=x&-x) t[x]++;}
	int query(int x){int ret=0;for (;x;x&=x-1) ret+=t[x];return ret;}
}t;
int x[N],y[N],n;
pair<double,double>a[N];
pair<int,int>c[N];
double b[N*2];
ll check(double r)
{
	int cnt=0,m=0;
	for (int i=1;i<=n;i++)
	{
		double dis=sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
		if (dis<=r) continue;
		m++;
		double A=atan2(y[i],x[i])-acos(r/dis),B=atan2(y[i],x[i])+acos(r/dis);
		if (A<=-pi) A+=pi*2;
		if (B>pi) B-=pi*2;
		if (A>B) swap(A,B);
		b[++cnt]=a[m].first=A;
		b[++cnt]=a[m].second=B;
	}
	ll ret=1LL*n*(n-1)/2;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=m;i++)
		c[i].first=lower_bound(b+1,b+1+cnt,a[i].first)-b,
		c[i].second=lower_bound(b+1,b+1+cnt,a[i].second)-b;
	sort(c+1,c+1+m);
	t.send(cnt);
	for (int i=1,j=1;i<=m;i++)
	{
		while (j<=i&&c[j].first<c[i].first) t.add(c[j++].second);
		ret-=t.query(c[j].second-1)-t.query(c[j].first);
	}
	return ret;
}

signed main()
{
	n=read(); ll k=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	double l=0,r=1e4*sqrt(2)+5;
	for (int i=1;i<=40;i++)
	{
		double mid=(l+r)/2;
		if (check(mid)<k) l=mid;
					 else r=mid;
	}
	printf("%.10lf\n",l);
	
	return 0;
}