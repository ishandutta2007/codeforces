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
#define N 800010
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
		for(lim=1,mxbit=0;lim<n+m;lim<<=1,mxbit++);
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
		for(i=0;i<resnum;++i)
		{
			ret.push_back(a1[i]);
		}
		return ret;
	}
}ntt;
ll p[30],sums=0,sumt[N],val[30],f[N];
string s,t;
int main(){
	ll i;
	for(i=0;i<26;i++)
	{
		val[i]=rnd()%mod;
		cin>>p[i];
		p[i]--;
	}
	cin>>s>>t;
	reverse(s.begin(),s.end());
	for(i=0;i<t.size();i++)
	{
		sumt[i+1]=(sumt[i]+val[t[i]-'a']*val[t[i]-'a'])%mod;
	}
	for(i=0;i<s.size();i++)
	{
		(sums+=val[s[i]-'a']*val[p[s[i]-'a']])%=mod;
	}
	vector<ll> v1,v2,v;
	for(i=0;i<s.size();i++)
	{
		v1.push_back(val[s[i]-'a']);
	}
	for(i=0;i<t.size();i++)
	{
		v2.push_back(val[t[i]-'a']);
	}
	v=ntt.do_ntt(v1,v2);
	for(i=0;i<=t.size()-s.size();i++)
	{
		f[i]=(f[i]+v[i+s.size()-1])%mod;
	}
	for(i=0;i<s.size();i++)
	{
		v1[i]=val[p[s[i]-'a']];
	}
	v=ntt.do_ntt(v1,v2);
	for(i=0;i<=t.size()-s.size();i++)
	{
		f[i]=(f[i]+v[i+s.size()-1])%mod;
		f[i]=(f[i]+mod-sums)%mod;
		f[i]=(f[i]+mod-((sumt[i+s.size()]-sumt[i])%mod))%mod;
		putchar(f[i]==0?'1':'0');
	}
	return 0;
}