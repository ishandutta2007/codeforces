#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll mul(ll a,ll b,ll mod)
{
	__int128 res=0;
	for(int i=0;i<35;i++)
		if(b>>i&1)res^=static_cast<__int128>(a)<<i;
	int d=63-__builtin_clzll(mod);
	for(int i=70;i>=d;i--)
		if(res>>i&1)res^=static_cast<__int128>(mod)<<(i-d);
	return static_cast<ll>(res);
}
inline ll pow(ll a,ll k,ll mod)
{
	ll res=1;
	while(k)
	{
		if(k&1)res=mul(res,a,mod);
		a=mul(a,a,mod);
		k>>=1;
	}
	return res;
}
ll solve(int n,ll mod)
{
	int l=(n+1)/2,r=n-l;
	map<ll,int> mp;
	ll now=1,pw=2;
	for(int i=0;i<=(1<<l);i++)
	{
		if(i)mp.emplace(now,i);
		now=mul(now,pw,mod);
	}
	now=1,pw=pow(mod>>1,1<<l,mod);
	for(int i=0;i<=(1<<r);i++)
	{
		if(mp.count(now))return mp[now]+i*(1LL<<l);
		now=mul(now,pw,mod);
	}
	return -1;
}
int main()
{
	char s[45];
	scanf("%s",s);
	int n=strlen(s),ost=find(s,s+n,'1')-s;
	if(ost==n)return 0*printf("-1\n");
	if(find(s+ost+1,s+n,'1')==s+n)return 0*printf("%d %d\n",ost+1,ost+2);
	ll mod=0;
	for(int i=ost;i<n;i++)
		if(s[i]=='1')mod|=1LL<<(i-ost);
	ll res=solve(n-ost,mod);
	return 0*printf("%lld %lld\n",ost+1,res+ost+1);
}