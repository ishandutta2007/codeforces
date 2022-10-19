//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 5000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
struct BIT{
	ll val[N];
	void init(ll x)
	{
		ll i;
		for(i=0;i<=x+5;i++)
		{
			val[i]=LINF;
		}
		return;
	}
	void upd(ll x,ll v)
	{
		x++;
		while(x<N)
		{
			val[x]=min(val[x],v);
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		x++;
		ll ret=LINF;
		while(x>0)
		{
			ret=min(ret,val[x]);
			x-=x&(-x);
		}
		return ret;
	}
}bit;
ll n,q,a[N],w[N],ans[N],dq[N],ed=0;
vector<pair<int,int> > qry[N];
int main(){
	n=rint(),q=rint();
	for(int i=0;i<n;++i)
	{
		a[i]=rint(),w[i]=rint();
	}
	dq[ed++]=n-1;
	bit.init(n);
	for(int i=0;i<q;++i)
	{
		ll x,y;
		x=rint()-1,y=rint()-1;
		qry[x].push_back(make_pair(y,i));
	}
	for(int i=n-2;i>=0;--i)
	{
		for(int j=ed-1;j>=0;--j)
		{
			bit.upd(dq[j],(a[dq[j]]-a[i])*(w[dq[j]]+w[i]));
			if(w[dq[j]]<=w[i])
			{
				break;
			}
		}
		for(int j=0;j<qry[i].size();++j)
		{
			ans[qry[i][j].S]=bit.qry(qry[i][j].F);
		}
		while(ed&&w[dq[ed-1]]>=w[i])
		{
			--ed;
		}
		dq[ed++]=i;
	}
	for(int i=0;i<q;++i)
	{
		rout(ans[i]),putchar('\n');
	}
	return 0;
}