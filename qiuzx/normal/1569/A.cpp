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
#define N 10000010
using namespace std;
ll n;
string s;
int main(){
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		for(i=0;i+1<s.size();i++)
		{
			if(s[i]=='a'&&s[i+1]=='b')
			{
				printf("%lld %lld\n",i+1,i+2);
				i=-1;
				break;
			}
			if(s[i]=='b'&&s[i+1]=='a')
			{
				printf("%lld %lld\n",i+1,i+2);
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			puts("-1 -1");
		}
	}
	return 0;
}