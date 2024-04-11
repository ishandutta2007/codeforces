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
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
ll mod,vals;
string s,t;
ll len,pw[N],pref[N],hval,z[N];
bool is_prime(ll x)
{
	ll i;
	for(i=2;i*i<=x&&i<x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
void getz(string ts)
{
	ll i,j,l,r;
	l=r=0;
	z[0]=ts.size();
	for(i=1;i<ts.size();++i)
	{
		if(i>r)
		{
			for(j=i;j<ts.size();++j)
			{
				if(ts[j]!=ts[j-i])
				{
					break;
				}
			}
			z[i]=j-i;
			l=i;
			r=j;
		}
		else if(i+z[i-l]>=r)
		{
			for(j=r;j<ts.size();++j)
			{
				if(ts[j]!=ts[j-i])
				{
					break;
				}
			}
			z[i]=j-i;
			l=i;
			r=j;
		}
		else
		{
			z[i]=z[i-l];
		}
	}
	return;
}
ll calc(ll l,ll r){return (pref[r+1]+mod-((pref[l]*pw[r-l+1])%mod))%mod;}
bool check(ll l1,ll r1,ll l2,ll r2)
{
	if(r2<s.size()&&l1>=0&&l2==r1+1&&l1<=r1&&l2<=r2)
	{
		if((calc(l1,r1)+calc(l2,r2))%mod==hval)
		{
			return true;
		}
	}
	return false;
}
int main(){
	ll i,j,stv=0;
	cin>>s>>t;
	i=(rnd()%(1000000100-100000000))+100000000;
	while(!is_prime(i))
	{
		i=(rnd()%(1000000100-100000000))+100000000;
	}
	mod=i;
	pw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*10)%mod;
	}
	len=t.size();
	getz(t+s);
	pref[0]=0;
	hval=0;
	for(i=0;i<len;i++)
	{
		hval=(hval*10+(t[i]-'0'))%mod;
	}
	for(i=0;i<s.size();i++)
	{
		pref[i+1]=(pref[i]*10+(s[i]-'0'))%mod;
	}
	ll ovl;
	for(i=0;i+len<=s.size();i++)
	{
		if(i+len-2<s.size())
		{
			if(check(i,i+len-2,i+len-1,i+2*len-3))
			{
				printf("%lld %lld\n%lld %lld",i+1,i+len-1,i+len,i+2*len-2);
				return 0;
			}
			if(check(i-len+1,i-1,i+1,i+len-1))
			{
				printf("%lld %lld\n%lld %lld",i-len+2,i,i+1,i+len-1);
				return 0;
			}
		}
		ovl=z[len+i];
		if(len-ovl>0)
		{
			if(check(i,i+len-1,i+len,i+2*len-ovl-1))
			{
				printf("%lld %lld\n%lld %lld\n",i+1,i+len,i+len+1,i+2*len-ovl);
				return 0;
			}
			if(check(i-len+ovl,i-1,i,i+len-1))
			{
				printf("%lld %lld\n%lld %lld\n",i-len+ovl+1,i,i+1,i+len);
				return 0;
			}
		}
		if(len-ovl-1>0)
		{
			if(check(i,i+len-1,i+len,i+2*len-ovl-2))
			{
				printf("%lld %lld\n%lld %lld\n",i+1,i+len,i+len+1,i+2*len-ovl-1);
				return 0;
			}
			if(check(i-len+ovl+1,i-1,i,i+len-1))
			{
				printf("%lld %lld\n%lld %lld\n",i-len+ovl+2,i,i+1,i+len);
				return 0;
			}
		}
	}
	return 0;
}