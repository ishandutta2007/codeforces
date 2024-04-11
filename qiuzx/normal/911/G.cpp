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
#define ll int
#define N 200010
#define B 400
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,q,a[N],fa[110];
bool upd[N];
vector<pair<pair<ll,ll>,pair<ll,ll> > > qry;
void recalc(ll x)
{
	ll i;
	for(i=0;i<qry.size();++i)
	{
		fa[qry[i].S.F]=qry[i].S.F;
	}
	for(i=qry.size()-1;i>=0;--i)
	{
		if(x>=qry[i].F.F&&x<=qry[i].F.S)
		{
			fa[qry[i].S.F]=fa[qry[i].S.S];
		}
	}
	return;
}
void update()
{
	ll i;
	for(i=0;i<110;++i)
	{
		fa[i]=i;
	}
	for(i=0;i<n;++i)
	{
		upd[i]=false;
	}
	for(i=0;i<qry.size();++i)
	{
		upd[qry[i].F.F]=upd[qry[i].F.S+1]=true;
	}
	for(i=0;i<n;++i)
	{
		if(upd[i])
		{
			recalc(i);
		}
		a[i]=fa[a[i]];
	}
	return;
}
int main(){
	ll i,l,r,x,y;
	n=rint();
	for(i=0;i<n;++i)
	{
		a[i]=rint();
	}
	q=rint();
	for(i=0;i<q;++i)
	{
		l=rint()-1,r=rint()-1,x=rint(),y=rint();
		qry.push_back(make_pair(make_pair(l,r),make_pair(x,y)));
		if(i==q-1||(i+1)%B==0)
		{
			update();
			qry.clear();
		}
	}
	for(i=0;i<n;++i)
	{
		rout(a[i]),putchar(' ');
	}
	return 0;
}