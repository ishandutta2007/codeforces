// By: Little09
// Problem: CF896C Willem, Chtholly and Seniorious
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF896C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;

const int N=100005;
int n,m,seed,vmax; 
int a[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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

int rnd()
{
	int res=seed;
	seed=(1ll*seed*7ll+13)%1000000007;
	return res;
}

struct point
{
	int l,r;
	mutable ll v;
	point(int a=-1,int b=-1,int c=0)
	{
		l=a,r=b,v=c;
	}
	bool operator < (const point & o) const
	{
		return l<o.l;
	}
};
set<point>odt;

auto split(int x)
{
	if (x>n) return odt.end();
	auto it=odt.lower_bound(point(x));
	if (it!=odt.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r;
	ll v=it->v;
	odt.erase(it);
	odt.insert(point(l,x-1,v));
	return odt.insert(point(x,r,v)).first;
}
void assign(int l,int r,ll v)
{
	auto itr=split(r+1),itl=split(l);
	odt.erase(itl,itr);
	odt.insert(point(l,r,v));
}
void add(int l,int r,ll v)
{
	auto itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) 
	{
		itl->v+=v;
	}
}
int askkth(int l,int r,int k)
{
	vector< pair<ll,ll> > v;
	v.clear();
	auto itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) 
	{
		v.push_back(make_pair(itl->v,(itl->r)-(itl->l)+1));
	}
	sort(v.begin(),v.end());
	for (auto it=v.begin();it!=v.end();it++)
	{
		if (k<=it->second) return it->first;
		else k-=it->second;
	}
	return -1;
}
ll ksm(ll x,ll y,ll mod)
{
	ll res=1;
	x%=mod;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll askexp(int l,int r,ll x,ll mod)
{
	auto itr=split(r+1),itl=split(l);
	ll ans=0;
	for (;itl!=itr;++itl) 
	{
		ll res=0;
		res=ksm(itl->v,x,mod)*((itl->r-itl->l+1)%mod)%mod;
		ans=(ans+res)%mod;
	}
	return ans;
}

signed main()
{
	n=read(),m=read(),seed=read(),vmax=read();
	for (int i=1;i<=n;i++) a[i]=(rnd()%vmax)+1;
	for (int i=1;i<=n;i++) odt.insert(point(i,i,a[i]));
	for (int i=1;i<=m;i++)
	{
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if (l>r) swap(l,r);
		if (op==1)
		{
			int x=rnd()%vmax+1;
			add(l,r,x);
		}
		else if (op==2)
		{
			int x=rnd()%vmax+1;
			assign(l,r,x);
		}
		else if (op==3)
		{
			int x=rnd()%(r-l+1)+1;
			printf("%lld\n",askkth(l,r,x));
		}
		else 
		{
			int x=rnd()%vmax+1,y=rnd()%vmax+1;
			printf("%lld\n",askexp(l,r,x,y)%y);
		}
	}
	return 0;
}