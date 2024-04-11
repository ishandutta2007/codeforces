//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
struct Ntt{
	ll n,m,rev[N],resnum,lim,mxbit;
	void NTT(ll* a,ll flag)
	{
		ll i,j,k,l;
		for(i=0;i<lim;i++)
		{
			if(rev[i]<i)
			{
				swap(a[i],a[rev[i]]);
			}
		}
		for(l=2;l<=lim;l<<=1)
		{
			i=l>>1;
			ll gn=ksm(3,(mod-1)/l);
			for(j=0;j<lim;j+=l)
			{
				ll g=1;
				for(k=0;k<i;++k)
				{
					ll x=(a[i+j+k]*g)%mod;
					a[i+j+k]=(a[j+k]+mod-x)%mod;
					a[j+k]=(a[j+k]+x)%mod;
					g=(g*gn)%mod;
				}
			}
		}
		if(flag==-1)
		{
			reverse(a+1,a+lim);
			ll inv=ksm(lim,mod-2);
			for(i=0;i<lim;i++)
			{
				a[i]=(a[i]*inv)%mod;
			}
		}
		return;
	}
	ll a1[N],a2[N];
	vector<ll> do_ntt(vector<ll> v1,vector<ll> v2)
	{
		ll i;
		vector<ll> ret;
		n=v1.size(),m=v2.size();
		resnum=n+m-1;
		for(lim=1,mxbit=0;lim<resnum;lim<<=1,mxbit++);
		--mxbit;
		for(i=0;i<lim;++i)
		{
			a1[i]=a2[i]=0;
		}
		for(i=0;i<n;++i)
		{
			a1[i]=v1[i];
		}
		for(i=0;i<m;++i)
		{
			a2[i]=v2[i];
		}
		rev[0]=0;
		for(i=1;i<lim;++i)
		{
			rev[i]=(rev[i>>1]>>1)|((i&1)<<mxbit);
		}
		NTT(a1,1);
		NTT(a2,1);
		for(i=0;i<lim;++i)
		{
			a1[i]=(a1[i]*a2[i])%mod;
		}
		NTT(a1,-1);
		ret.clear();
		resnum=min(resnum,(ll)100010);
		for(i=0;i<resnum;++i)
		{
			ret.push_back(a1[i]);
		}
		return ret;
	}
}ntt;
struct Poly{
	vector<ll> getinv(vector<ll> v,ll r)
	{
		if(r==0)
		{
			return {ksm(v[0],mod-2)};
		}
		vector<ll> lst=getinv(v,r>>1),nw,cur;
		ll i;
		for(i=0;i<=r;i++)
		{
			cur.push_back(v[i]);
		}
		nw=ntt.do_ntt(lst,lst);
		cur=ntt.do_ntt(cur,nw);
		for(i=0;i<lst.size();i++)
		{
			lst[i]=(lst[i]*2)%mod;
		}
		nw.clear();
		for(i=0;i<=r;i++)
		{
			nw.push_back((((i>=lst.size())?0:lst[i])+mod-((i>=cur.size())?0:cur[i]))%mod);
		}
		return nw;
	}
	vector<ll> getsq(vector<ll> v,ll r)
	{
		if(r==0)
		{
			assert(v[0]==1);
			return {1};
		}
		vector<ll> lst=getsq(v,r>>1),nw,cur;
		ll i;
		nw=ntt.do_ntt(lst,lst);
		for(i=0;i<=r;i++)
		{
			cur.push_back((v[i]+((i>=nw.size())?0:nw[i]))%mod);
		}
		for(i=0;i<lst.size();i++)
		{
			lst[i]=(lst[i]*2)%mod;
		}
		while(lst.size()<=r)
		{
			lst.push_back(0);
		}
		lst=getinv(lst,lst.size()-1);
		nw=ntt.do_ntt(lst,cur);
		return nw;
	}
}pol;
ll n,m;
vector<ll> c;
int main(){
	ll i,x;
	scanf("%lld%lld",&n,&m);
	c.resize(m+1);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(x<=m)
		{
			c[x]++;
		}
	}
	c[0]=1;
	for(i=1;i<=m;i++)
	{
		c[i]=(mod-(4*c[i])%mod);
	}
	c=pol.getsq(c,m);
	c[0]=(c[0]+1)%mod;
	c=pol.getinv(c,m);
	for(i=1;i<=m;i++)
	{
		printf("%lld\n",(c[i]*2)%mod);
	}
	return 0;
}