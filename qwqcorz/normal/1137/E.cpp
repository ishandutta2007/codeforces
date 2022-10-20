#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll sumb=0,sums=0;
struct WangCe_TuBao
{
	double x[N];
	ll k[N],b[N],top,now;
	void clear()
	{
		top=now=1;
		k[top]=0;
		b[top]=0;
	}
	void fix(ll pos)
	{
		while (now>1&&x[now]<=pos) now--;
	}
	double get(ll K,ll B,ll top)
	{
		return 1.0*(B-b[top])/(k[top]-K);
	}
	void insert(ll K,ll B)
	{
		while (top>1&&get(K,B,top)>x[top]) top--;
		k[++top]=K;
		b[top]=B;
		x[top]=get(K,B,top-1);
		if (sums<x[top]) now=top;
		now=min(now,top);
	}
	void query(ll x,ll y)
	{
		print(k[now]+1,' ');
		print(x*k[now]+b[now]+y);
	}
}t;

signed main()
{
	ll n=read(),m=read();
	t.clear();
	while (m--)
	{
		ll opt=read();
		if (opt==1)
		{
			t.clear();
			n+=read();
			sumb=sums=0;
		}
		if (opt==2)
		{
			t.insert(n,-sumb-sums*n);
			n+=read();
		}
		if (opt==3)
		{
			ll b=read(),s=read();
			sumb+=b;
			sums+=s;
			t.fix(sums);
		}
//		puts("");
		t.query(sums,sumb);
//		for (int i=1;i<=t.top;i++)
//		{
//			print(t.k[i],',');
//			print(t.b[i],',');
//			print(t.x[i]);
//		}
//		print(sums,':');
//		print(sumb,':');
//		print(t.now);
	}
	
	return 0;
}