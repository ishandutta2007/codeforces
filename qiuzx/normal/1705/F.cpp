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
#define N 1010
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll n,ans[N],qry[N],res[N];
ll query()
{
	ll i;
	for(i=0;i<n;i++)
	{
		putchar(qry[i]?'T':'F');
	}
	puts("");
	fflush(stdout);
//	i=0;
//	for(int j=0;j<n;j++) i+=(qry[j]==res[j]);
	scanf("%lld",&i);
	return i;
}
int main(){
	ll i,j;
	string s;
	for(i=0;i<1000;i++)
	{
		res[i]=rnd()%2;
	}
	scanf("%lld",&n);
	memset(ans,0,sizeof(ans));
	memset(qry,0,sizeof(qry));
	ll pre=query();
	if(pre==n)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		qry[i]=(i&1);
	}
	ll pre2=query();
	if(pre2==n)
	{
		return 0;
	}
	for(i=0;i<n;i+=3)
	{
		if(i==n-1)
		{
			for(j=0;j<n;j++)
			{
				qry[j]=ans[j];
			}
			pre=query();
			if(pre==n||pre==-1)
			{
				return 0;
			}
			ans[i]^=1;
			break;
		}
		if(i==n-2)
		{
			for(j=0;j<n;j++)
			{
				qry[j]=ans[j];
			}
			pre=query();
			if(pre==n||pre==-1)
			{
				return 0;
			}
			if(pre==n-2)
			{
				ans[i]^=1;ans[i+1]^=1;
				break;
			}
			assert(pre==n-1);
			ans[i]^=1;qry[i]^=1;
			ll cur=query();
			if(cur==n||cur==-1)
			{
				return 0;
			}
			ans[i]^=1;ans[i+1]^=1;
			break;
		}
		memset(qry,0,sizeof(qry));
		qry[i]=qry[i+1]=1;
		ll cur=query();
		if(cur==n||cur==-1)
		{
			return 0;
		}
		if(cur==pre+2)
		{
			ans[i]=ans[i+1]=1;
			i--;
			continue;
		}
		if(cur==pre-2)
		{
			ans[i]=ans[i+1]=0;
			i--;
			continue;
		}
		for(j=0;j<n;j++)
		{
			qry[j]=(j&1);
		}
		qry[i]^=1;qry[i+1]^=1;qry[i+2]^=1;
		cur=query();
		if(cur==n||cur==-1)
		{
			return 0;
		}
		if(cur==pre2+3)
		{
			ans[i]=qry[i];ans[i+1]=qry[i+1];ans[i+2]=qry[i+2];
		}
		else if(cur==pre2+1)
		{
			ans[i]=qry[i];ans[i+1]=qry[i+1];ans[i+2]=qry[i+2]^1;
		}
		else if(cur==pre2-1)
		{
			ans[i]=qry[i]^1;ans[i+1]=qry[i+1]^1;ans[i+2]=qry[i+2];
		}
		else
		{
			ans[i]=qry[i]^1;ans[i+1]=qry[i+1]^1;ans[i+2]=qry[i+2]^1;
		}
	}
	for(i=0;i<n;i++)
	{
		qry[i]=ans[i];
	}
	if(query()!=n)
	{
		for(i=0;i<n;i++)
		{
			cout<<res[i];
		}
		puts("");
	}
	return 0;
}