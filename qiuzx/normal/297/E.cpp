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
#define N 200010
using namespace std;
struct BIT{
	ll val[N];
	void init()
	{
		memset(val,0,sizeof(val));
		return;
	}
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		ll ret=0;
		++x;
		while(x>0)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit;
ll n,insnum[N],crsnum[N],lft[N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,l,r,tot=0,sum=0;
	memset(lft,-1,sizeof(lft));
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>l>>r;
		l--,r--;
		if(l>r)
		{
			swap(l,r);
		}
		lft[r]=l;
	}
	bit.init();
	l=0;
	ans=n*(n-1)*(n-2)/6;
	for(i=0;i<2*n;i++)
	{
		if(lft[i]!=-1)
		{
			insnum[lft[i]]=insnum[i]=l-bit.qry(lft[i]);
			bit.upd(lft[i],1);
			++l;
			crsnum[i]=i-lft[i]-2*insnum[i]-1;
			tot+=crsnum[i];
			sum+=crsnum[i]*(crsnum[i]-1)/2;
		}
	}
	tot/=2;
	ans-=(tot*(n-2)-sum);
	tot=sum=0;
	bit.init();
	for(i=0;i<2*n;i++)
	{
		if(lft[i]==-1)
		{
			ans-=sum;
		}
		else
		{
			ans-=(sum-bit.qry(lft[i]));
			sum+=insnum[i];
			bit.upd(lft[i],insnum[i]);
		}
	}
	sum=0;
	for(i=2*n-1;i>=0;i--)
	{
		if(lft[i]!=-1)
		{
			ans-=sum;
		}
		else
		{
			sum+=insnum[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}