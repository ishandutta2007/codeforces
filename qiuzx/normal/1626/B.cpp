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
#define N 200010
using namespace std;
string s;
void print(ll x)
{
	ll i;
	for(i=0;i<x;i++)
	{
		cout<<s[i];
	}
	cout<<(s[x]-'0')+(s[x+1]-'0');
	for(i=x+2;i<s.size();i++)
	{
		cout<<s[i];
	}
	cout<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>s;
		for(i=s.size()-2;i>=0;i--)
		{
			if((s[i]-'0')+(s[i+1]-'0')>=10)
			{
				print(i);
				i=-100;
				break;
			}
		}
		if(i==-100)
		{
			continue;
		}
		print(0);
	}
	return 0;
}