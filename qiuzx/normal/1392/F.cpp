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
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll n,h[N],rest[N],pure,more;
vector<ll> st,sz;
bool check(ll step,ll st,ll pre)
{
	if(pre==0)
	{
		return true;
	}
	pure=step/pre,more=step%pre;
	if(more+st>=pre-1)
	{
		pure++;
	}
	if(h[pre-1]+pure+2>h[pre]-step)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,l,r,mid,lst;
	n=rint();
	for(i=0;i<n;i++)
	{
		h[i]=rint();
	}
	lst=-1;
	for(i=0;i<n;i++)
	{
		l=0;
		r=LINF+1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid,lst,i))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		check(l,lst,i);
		h[i]-=l;
		if(i>0)
		{
			h[i-1]+=pure;
			lst=(lst+more)%i;
			if(h[i-1]==h[i])
			{
				lst=i-1;
			}
			else if(lst==i-1)
			{
				lst=-1;
			}
		}
	}
	for(i=n-2;i>=0;i--)
	{
		if(i==lst)
		{
			h[i]=h[i+1];
		}
		else
		{
			h[i]=h[i+1]-1;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld ",h[i]);
	}
	return 0;
}