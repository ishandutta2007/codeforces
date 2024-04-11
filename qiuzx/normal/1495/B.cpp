#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,p[N],lenl[N],lenr[N],ans,mx=0,mxid=-1;
vector<ll> pk1,pk2;
bool check(ll x)
{
	if(p[1]<p[0]&&lenr[0]>=mx)
	{
		return false;
	}
	if(p[n-2]<p[n-1]&&lenl[n-1]>=mx)
	{
		return false;
	}
	if(lenr[x]==mx&&lenl[x]==mx&&mx%2==0)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,lst=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&p[i]);
	}
	lenl[0]=0;
	for(i=1;i+1<n;i++)
	{
		lenl[i]=i-lst;
		if(p[i]>p[i-1]&&p[i]>p[i+1])
		{
			pk1.push_back(i);
			lst=i;
		}
		else if(p[i]<p[i-1]&&p[i]<p[i+1])
		{
			lst=i;
		}
	}
	lenl[n-1]=n-1-lst;
	lst=n-1;
	lenr[n-1]=0;
	for(i=n-2;i>0;i--)
	{
		lenr[i]=lst-i;
		if(p[i]>p[i-1]&&p[i]>p[i+1])
		{
			lst=i;
		}
		if(p[i]<p[i-1]&&p[i]<p[i+1])
		{
			lst=i;
		}
	}
	lenr[0]=lst;
	for(i=0;i<pk1.size();i++)
	{
		if(mx<max(lenl[pk1[i]],lenr[pk1[i]]))
		{
			mx=max(lenl[pk1[i]],lenr[pk1[i]]);
			mxid=pk1[i];
		}
		else if(mx==max(lenl[pk1[i]],lenr[pk1[i]]))
		{
			mxid=-100;
		}
	}
	if(mxid<0)
	{
		puts("0");
	}
	else if(check(mxid))
	{
		puts("1");
	}
	else
	{
		puts("0");
	}
	return 0;
}