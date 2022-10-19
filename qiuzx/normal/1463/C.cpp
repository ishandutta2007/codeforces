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
ll n,t[N],mt[N],ans,curt,curx,curid;
bool dir;
bool reach_time(ll x)
{
	ll ct=t[x];
	if(abs(curx-mt[curid])>ct-curt)
	{
		return false;
	}
	return true;
}
void upd(ll x)
{
	curx=mt[curid];
	curt=t[x];
	curid=x;
	dir=(mt[x]>curx);
	return;
}
bool is_suc(ll x)
{
	ll des=mt[x];
	if(dir)
	{
		if(des>mt[curid])
		{
			return false;
		}
		if(des-curx>=t[x]-curt&&des-curx<=t[x+1]-curt)
		{
			return true;
		}
		return false;
	}
	if(des<mt[curid])
	{
		return false;
	}
	if(curx-des>=t[x]-curt&&curx-des<=t[x+1]-curt)
	{
		return true;
	}
	return false;
}
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld",&t[i],&mt[i]);
		}
		t[n]=LINF;
		ans=0;
		dir=(mt[0]>0);
		curt=t[0];
		curx=0;
		curid=0;
		for(i=0;i<n;i++)
		{
			if(reach_time(i))
			{
				//cout<<"update: "<<i<<endl;
				upd(i);
			}
			//if(is_suc(i))
			//{
			//	cout<<i<<endl;
			//}
			ans+=is_suc(i);
		}
		//printf("THE ANSWER IS: %lld\n",ans);
		printf("%lld\n",ans);
	}
	return 0;
}