#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long



int psum(long long v)
{
	long long ans = (v*(v+MOD-1))%MOD;
	ans = (ans*500000004LL)%MOD;
	return (int)ans;
}

pair<ll,ll> getDP(int x,int y,int k)	//num,sum
{
	if(x==0 || y==0 || k==0) return make_pair(0,0);
	if(x==1)
	{
		int low = min(y,k);
		return make_pair(low,psum(low));
	}
	if(y==1)
	{
		int low = min(x,k);
		return make_pair(low,psum(low));
	}
	if(k==1)
	{
		int low = min(x,y);
		return make_pair(low,low);
	}
	pair<ll,ll> v1 = getDP((x+1)/2,(y+1)/2,(k+1)/2);
	pair<ll,ll> v2 = getDP(x/2,(y+1)/2,k/2);	
	pair<ll,ll> v3 = getDP((x+1)/2,y/2,k/2);
	pair<ll,ll> v4 = getDP(x/2,y/2,(k+1)/2);
	int num = (((long long)v1.first) + ((long long)v2.first) + ((long long)v3.first) + ((long long)v4.first))%MOD;
	int ans = (2LL*v1.second + MOD - v1.first)%MOD;
	ans = (ans + 2LL*v4.second + MOD - v4.first)%MOD;
	ans = (ans + 2LL*v2.second + 2LL*v3.second)%MOD;
	return make_pair(num,ans);
}

int mask[31];

pair<ll,ll> getWays(int x,int y,int k)
{
	if(x==0 || y==0 || k==0) return make_pair(0,0);
	int totNum = 0;
	int totSum = 0;
	for(int t=0;t<2;t++)
	{
		for(int i=30;i>=0;i--) if(x&(1<<i))
		{
			x ^= (1<<i);
			for(int j=i-1;j>=0;j--) if(y&(1<<j))
			{
				y ^= (1<<j);
				if(((x^y)>>i) < (k>>i))
				{
					long long cnum = ((1LL<<i)*(1LL<<j))%MOD;
					totNum = (totNum + cnum)%MOD;
					totSum = (totSum + (1LL<<j)*psum(1LL<<i))%MOD;
					totSum = (totSum + (((x^y)>>i)<<i)*cnum)%MOD;
				}
				else if(((x^y)>>i) == (k>>i))
				{
					long long lowk = (k&((1<<i)-1));
					long long cnum = (lowk*(1LL<<j))%MOD;
					totNum = (totNum + cnum)%MOD;
					totSum = (totSum + (1LL<<j)*psum(lowk))%MOD;
					totSum = (totSum + (((x^y)>>i)<<i)*cnum)%MOD;
				}
				
				y ^= (1<<j);
			}
			x ^= (1<<i);
		}
		swap(x,y);
	}
	for(int i=30;i>=0;i--) if(x&(1<<i)) if(y&(1<<i))
	{
		x ^= (1<<i);
		y ^= (1<<i);
		if(((x^y)>>i) < (k>>i))
		{
			long long cnum = ((1LL<<i)*(1LL<<i))%MOD;
			totNum = (totNum + cnum)%MOD;
			totSum = (totSum + (1LL<<i)*psum(1LL<<i))%MOD;
			totSum = (totSum + (((x^y)>>i)<<i)*cnum)%MOD;
		}
		else if(((x^y)>>i) == (k>>i))
		{
			long long lowk = (k&((1<<i)-1));
			long long cnum = (lowk*(1LL<<i))%MOD;
			totNum = (totNum + cnum)%MOD;
			totSum = (totSum + (1LL<<i)*psum(lowk))%MOD;
			totSum = (totSum + (((x^y)>>i)<<i)*cnum)%MOD;
		}
		x ^= (1<<i);
		y ^= (1<<i);
	}
	return make_pair(totNum,(totNum+totSum)%MOD);
}

int main()
{
	int Q,x1,y1,x2,y2,k;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		int ans = getWays(x2,y2,k).second;
		ans = (ans + MOD - getWays(x2,y1-1,k).second)%MOD;
		ans = (ans + MOD - getWays(x1-1,y2,k).second)%MOD;
		ans = (ans + getWays(x1-1,y1-1,k).second)%MOD;
		cout << ans << '\n';
		
	}
}