#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll gcd(ll a,ll b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
ll qmul(ll x,ll y,ll md)
{
	ll ret=0;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret+x)%md;
		}
		x=(x+x)%md;
		y>>=1;
	}
	return ret;
}
ll qpow(ll x,ll y,ll md)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=qmul(ret,x,md);
		}
		x=qmul(x,x,md);
		y>>=1;
	}
	return ret;
}
bool mr(ll x)
{
	if(x==1)
	{
		return false;
	}
	if(x==2)
	{
		return true;
	}
	if(x%2==0)
	{
		return false;
	}
	ll m=x-1,t=1,q,i;
	while(m%2==0)
	{
		m>>=1;
		++t;
	}
	for(i=0;i<20;++i)
	{
		ll a=(rnd()%(x-1))+1;
		ll cur=qpow(a,m,x);
		for(q=0;q<t;q++)
		{
			ll lst=cur;
			cur=qmul(cur,cur,x);
			if(cur==1&&lst!=1&&lst!=x-1)
			{
				return false;
			}
		}
		if(cur!=1)
		{
			return false;
		}
	}
	return true;
}
ll curad=1;
ll f(ll x,ll y,ll md)
{
	return (((__int128)x*(__int128)x)%md+y)%md;
}
ll pr(ll x)
{
	if(x%2==0)
	{
		return 2;
	}
	ll st1=f(0,curad,x),st2=f(f(0,curad,x),curad,x),i;
	while(st1!=st2)
	{
		ll x1=st1,x2=st2,pro=1;
		for(i=0;i<=60;++i)
		{
			st1=f(st1,curad,x);
			st2=f(f(st2,curad,x),curad,x);
			pro=qmul(pro,abs(st1-st2),x);
		}
		ll d=gcd(pro,x);
		if(d==1)
		{
			continue;
		}
		if(d<x)
		{
			return d;
		}
		st1=x1,st2=x2;
		for(i=0;i<=60;++i)
		{
			st1=f(st1,curad,x);
			st2=f(f(st2,curad,x),curad,x);
			d=gcd(abs(st1-st2),x);
			if(d>1)
			{
				return d%x;
			}
		}
		return 0;
	}
	return 0;
}
map<ll,ll> posp;
void solve(ll x)
{
	if(mr(x))
	{
		posp[x]++;
		return;
	}
	if(x==1)
	{
		return;
	}
	curad=(rnd()%(x-1))+1;
	ll p=pr(x);
	while(p==0)
	{
		curad=(rnd()%(x-1))+1;
		p=pr(x);
	}
	solve(x/p);
	solve(p);
	return;
}
ll n,dx,dy,a[N],mask1[(1<<15)+10],mask2[(1<<15)+10],ans=0;
vector<pair<ll,ll> > prm,prm2;
int main(){
	ll i,j;
	scanf("%lld%lld%lld",&n,&dx,&dy);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(dy%dx!=0)
	{
		puts("0");
		return 0;
	}
	solve(dy);
	for(map<ll,ll>::iterator it=posp.begin();it!=posp.end();it++)
	{
		prm2.push_back(*it);
	}
	ll tt=dx;
	for(i=0;i<prm2.size();i++)
	{
		ll cc=0;
		while(tt%prm2[i].F==0)
		{
			tt/=prm2[i].F;
			cc++;
		}
		prm.push_back(make_pair(prm2[i].F,cc));
	}
	for(i=0;i<n;i++)
	{
		tt=a[i];
		ll cc,curm=0;
		for(j=0;j<prm.size();j++)
		{
			cc=0;
			while(tt%prm[j].F==0)
			{
				tt/=prm[j].F;
				cc++;
			}
			if(cc<prm[j].S)
			{
				curm=-1;
				break;
			}
			if(cc==prm[j].S||prm[j].S==prm2[j].S)
			{
				curm|=(1<<j);
			}
		}
		if(curm!=-1)
		{
			mask1[curm]++;
		}
	}
	for(i=0;i<n;i++)
	{
		tt=a[i];
		ll cc,curm=0;
		for(j=0;j<prm2.size();j++)
		{
			cc=0;
			while(tt%prm2[j].F==0)
			{
				tt/=prm2[j].F;
				cc++;
			}
			if(cc>prm2[j].S)
			{
				curm=-1;
				break;
			}
			if(cc==prm2[j].S||prm[j].S==prm2[j].S)
			{
				curm|=(1<<j);
			}
		}
		if(tt>1)
		{
			curm=-1;
		}
		if(curm!=-1)
		{
			mask2[curm]++;
		}
	}
	for(i=0;i<(1<<prm.size());i++)
	{
		ll ndmask=((1<<prm.size())-1)^i;
		for(j=i;j>0;j=i&(j-1))
		{
			ans+=mask1[i]*mask2[ndmask|j];
		}
		ans+=mask1[i]*mask2[ndmask];
	}
	printf("%lld\n",ans);
	return 0;
}