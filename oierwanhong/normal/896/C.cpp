#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
void write(ll x)
{
	if(x==0)
	{
		putchar('0');
		putchar(' ');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	ll s[21],top=0;
	while(x)
	{
		s[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(s[i]+'0');
	putchar(' ');
}


struct node
{
	ll l;
	mutable ll r,v;
	node(ll _l,ll _r=-1,ll _v=0)
	{
		l=_l,r=_r,v=_v;
	}
	bool operator <(const node &t)const
	{
		return l<t.l;
	}
};
std::set<node>s;
typedef std::set<node>::iterator sit;
sit split(ll num)
{
	sit tl=s.lower_bound(node(num));
	if(tl!=s.end()&&tl->l==num)return tl;
	--tl;
	ll L=tl->l,R=tl->r,V=tl->v;
	s.erase(tl);
	s.insert(node(L,num-1,V));
	sit tr=s.insert(node(num,R,V)).first;
	
	return tr;
}
void assign(ll l,ll r,ll v)
{
	sit tl=split(l),tr=split(r+1);
	s.erase(tl,tr);
	s.insert(node(l,r,v)); 
}

void add(ll l,ll r,ll v)
{
	sit tl=split(l),tr=split(r+1);
	while(tl!=tr)
	{
		tl->v+=v;
		++tl;
	}
}
typedef std::pair<ll,ll> pll;
std::vector<pll>a;//pair<value,len>
ll rank(ll l,ll r,ll k)
{
	a.clear();
	sit tl=split(l),tr=split(r+1);
	while(tl!=tr)
	{
		a.push_back(pll(tl->v,tl->r-tl->l+1));
		++tl;
	}
	std::sort(a.begin(),a.end());
	for(std::vector<pll>::iterator it=a.begin();it!=a.end();++it)
		if((k-=it->second)<=0)return it->first;
	return -1;
}
ll qpow(ll a,ll p,ll mod)
{
	a%=mod;
	ll res=1;
	while(p)
	{
		if(p&1)res=(res*a)%mod;
		p>>=1;
		a=(a*a)%mod;
	}
	return res;
}
ll sum(ll l,ll r,ll p,ll mod)
{
	sit tl=split(l),tr=split(r+1);
	ll res=0;
	while(tl!=tr)
	{
		res=(res+(tl->r-tl->l+1)*qpow(tl->v,p,mod))%mod;
		++tl;
	}
	return res;
}

ll n,m,sed,vmax;
ll rnd()
{
	ll ret=sed;
	sed=(sed*7+13)%1000000007;
	return ret;
}
int main()
{
	n=read(),m=read(),sed=read(),vmax=read();
	for(ll i=1;i<=n;++i)
		s.insert(node(i,i,rnd()%vmax+1));
	for(ll i=1;i<=m;++i)
	{
		ll op,l,r,x,y;
		op=rnd()%4+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if(l>r)std::swap(l,r);
		if(op==3)x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1;
		switch(op)
		{
			case 1:add(l,r,x);break;
			case 2:assign(l,r,x);break;
			case 3:write(rank(l,r,x));putchar('\n');break;
			case 4:write(sum(l,r,x,y));putchar('\n');break;
		}
	}
	return 0;
}