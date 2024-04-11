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
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
string s,l,r;
ll hsl[N],hsr[N],hss[N],pw[N],dp[N],upd[N],bas=114514;
ll calcl(ll lo,ll hi){return (lo>hi)?0:(hsl[hi+1]+mod-(hsl[lo]*pw[hi-lo+1])%mod)%mod;}
ll calcr(ll lo,ll hi){return (lo>hi)?0:(hsr[hi+1]+mod-(hsr[lo]*pw[hi-lo+1])%mod)%mod;}
ll calcs(ll lo,ll hi){return (lo>hi)?0:(hss[hi+1]+mod-(hss[lo]*pw[hi-lo+1])%mod)%mod;}
ll lstr[N],lstl[N];
bool checkr(ll x)
{
	ll lo=0,hi=r.size()+1,mid;
	while(lo+1<hi)
	{
		mid=(lo+hi)>>1;
		if(calcr(0,mid-1)==calcs(x,x+mid-1))
		{
			lo=mid;
		}
		else
		{
			hi=mid;
		}
	}
	if(lo==r.size())
	{
		return true;
	}
	return (s[x+lo]<=r[lo]);
}
bool checkl(ll x)
{
	ll lo=0,hi=l.size()+1,mid;
	while(lo+1<hi)
	{
		mid=(lo+hi)>>1;
		if(calcl(0,mid-1)==calcs(x,x+mid-1))
		{
			lo=mid;
		}
		else
		{
			hi=mid;
		}
	}
	if(lo==l.size())
	{
		return true;
	}
	return (s[x+lo]>=l[lo]);
}
bool isokl(ll lo,ll hi)
{
	if(hi-lo<l.size())
	{
		return false;
	}
	if(hi-lo>l.size())
	{
		return true;
	}
	ll i;
	for(i=lo;i<hi;i++)
	{
		if(s[i]!=l[i-lo])
		{
			return (s[i]>l[i-lo]);
		}
	}
	return true;
}
bool isokr(ll lo,ll hi)
{
	if(hi-lo>r.size())
	{
		return false;
	}
	if(hi-lo<r.size())
	{
		return true;
	}
	ll i;
	for(i=lo;i<hi;i++)
	{
		if(s[i]!=r[i-lo])
		{
			return (s[i]<r[i-lo]);
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,lo,hi,mid;
	cin>>s>>l>>r;
	pw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*bas)%mod;
	}
	for(i=0;i<s.size();i++)
	{
		hss[i+1]=(hss[i]*bas+(s[i]-'0'))%mod;
	}
	for(i=0;i<l.size();i++)
	{
		hsl[i+1]=(hsl[i]*bas+(l[i]-'0'))%mod;
	}
	for(i=0;i<r.size();i++)
	{
		hsr[i+1]=(hsr[i]*bas+(r[i]-'0'))%mod;
	}
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			continue;
		}
		if(i+r.size()>s.size())
		{
			lstr[i]=s.size();
		}
		else
		{
			lstr[i]=i+r.size()-1+checkr(i);
			if(lstr[i]>s.size())
			{
				lstr[i]=s.size();
			}
		}
		if(i+l.size()>s.size())
		{
			lstl[i]=INF;
		}
		else
		{
			lstl[i]=i+l.size()+1-checkl(i);
			if(lstl[i]>s.size())
			{
				lstl[i]=INF;
			}
		}
	}
	dp[0]=1;
	for(i=0;i<=s.size();i++)
	{
		if(i)
		{
			upd[i]=(upd[i]+upd[i-1])%mod;
		}
		dp[i]=(dp[i]+upd[i])%mod;
		if(i==s.size())
		{
			break;
		}
		if(s[i]!='0')
		{
			if(lstl[i]<INF)
			{
				upd[lstl[i]]=(upd[lstl[i]]+dp[i])%mod;
				upd[lstr[i]+1]=(upd[lstr[i]+1]+mod-dp[i])%mod;
			}
		}
		else if(l=="0")
		{
			dp[i+1]=(dp[i+1]+dp[i])%mod;
		}
	}
	cout<<dp[s.size()]<<endl;
	return 0;
}