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
ll a,b;
int main(){
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(a==0&&b==0)
		{
			puts("0");
		}
		else if(a==b)
		{
			puts("1");
		}
		else if((a+b)&1)
		{
			puts("-1");
		}
		else
		{
			puts("2");
		}
	}
	return 0;
}