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
#define ll long long
#define N 110
using namespace std;
string s;
ll x;
int main(){
	cin>>s>>x;
	if(s=="ABC")
	{
		if(x<2000)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	else if(s=="ARC")
	{
		if(x<2800)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	else if(s=="AGC")
	{
		if(x>=1200)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	else
	{
		puts("NO");
	}
	return 0;
}