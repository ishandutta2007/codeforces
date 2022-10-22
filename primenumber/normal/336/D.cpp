#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>

#define rep(i,n)	for(int i = 0;i < (n);i++)
#define rep2(i,n)	for(int i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

vector<long long> ary;

long long powmod(long long b,long long i,long long mod)
{
	if(i == 1)
		return b;
	else if(i % 2)
	{
		long long h = powmod(b,i/2,mod);
		return (((h*h)%mod)*b)%mod;
	}
	else
	{
		long long h = powmod(b,i/2,mod);
		return (h*h)%mod;
	}
}

long long cmb(long long n,long long m)
{
	long long c = 1;
	ary[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		c *= (m+i);
		c %= 1000000007;
		c *= powmod(i,1000000005,1000000007);
		c %= 1000000007;
		ary[i] = c;
	}
	return c;
}

long long ans(long long n,long long m,long long g)
{
	if(m == 0)
	{
		return (n % 2) ^ g;
	}
	if(n == 0)
	{
		if(m == 1)
			return g;
		else
			return 1-g;
	}
	else if(g == 1)
		return ans(n-1,m,0);
	else
		return (ans(n-1,m,1)+ary[n])%1000000007;
}

int main()
{
	int n,m,g;
	cin >> n >> m >> g;
	ary = vector<long long>(n+1);
	cmb(n,m-1);
	cout << ans(n,m,g) << endl;
	return 0;
}