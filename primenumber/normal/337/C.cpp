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

const int mod = 1000000009;

struct mat
{
	long long a;
	long long b;
	long long c;
	long long d;
};

mat calc(mat base,int index)
{
	if(index == 1)
		return base;
	else
	{
		mat h = calc(base,index/2);
		mat hsq = {h.a*h.a+h.b*h.c,h.b*(h.a+h.d),h.c*(h.a+h.d),h.d*h.d+h.b*h.c};
		hsq.a %= mod;
		hsq.b %= mod;
		hsq.c %= mod;
		hsq.d %= mod;
		if((index%2)==0)
			return hsq;
		else
		{
			mat hss = {
				hsq.a*base.a+hsq.b*base.c,
				hsq.a*base.b+hsq.b*base.d,
				hsq.c*base.a+hsq.d*base.c,
				hsq.c*base.b+hsq.d*base.d
			};
			hss.a%=mod;
			hss.b%=mod;
			hss.c%=mod;
			hss.d%=mod;
			return hss;
		}
	}
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(n/k<=n-m)
	{
		cout<<m<<endl;
	}
	else
	{
		int c = n/k-n+m;
		mat mt = {2,(2*k)%mod,0,1};
		//cerr<<mt.a<<' '<<mt.b<<'\n'<<mt.c<<' '<<mt.d<<endl;
		mat res = calc(mt,c);
		//cerr<<res.a<<' '<<res.b<<'\n'<<res.c<<' '<<res.d<<endl;
		long long score = res.b+(m-c*k);
		score%=mod;
		cout<<score<<endl;
	}
	return 0;
}