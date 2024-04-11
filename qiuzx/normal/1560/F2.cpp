//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,k,ans;
vector<ll> num;
bool can_plc(ll mask,ll plc,ll dig,bool is_sm)
{
	if(mask>0||dig>0)
	{
		mask|=(1<<dig);
	}
	if(__builtin_popcount(mask)!=k)
	{
		return (__builtin_popcount(mask)<k);
	}
	ll mxdig=-1,i;
	for(i=10;i>=0;i--)
	{
		if(mask&(1<<i))
		{
			mxdig=i;
			break;
		}
	}
	for(i=plc+1;i<num.size();i++)
	{
		is_sm|=(num[i]<mxdig);
		if((!is_sm)&&num[i]>mxdig)
		{
			return false;
		}
	}
	return true;
}
void dfs(ll mask,ll x,bool is_sm)
{
	if(x>=num.size())
	{
		return;
	}
	ll i;
	for(i=0;i<=9;i++)
	{
		if(is_sm==false&&i<num[x])
		{
			continue;
		}
		bool nw_sm=(is_sm||(i>num[x]));
		if(can_plc(mask,x,i,nw_sm))
		{
			ans=ans*10+i;
			if(i==0&&mask==0)
			{
				dfs(0,x+1,nw_sm);
			}
			else
			{
				dfs(mask|(1<<i),x+1,nw_sm);
			}
			break;
		}
	}
	return;
}
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		num.clear();
		while(n>0)
		{
			num.push_back(n%10);
			n/=10;
		}
		num.push_back(0);
		reverse(num.begin(),num.end());
		ans=0;
		dfs(0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}