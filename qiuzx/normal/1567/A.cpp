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
ll n;
string s;
int main(){
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		for(i=0;i<n;i++)
		{
			if(s[i]=='U')
			{
				putchar('D');
			}
			else if(s[i]=='D')
			{
				putchar('U');
			}
			else
			{
				putchar(s[i]);
			}
		}
		puts("");
	}
	return 0;
}