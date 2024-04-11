#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
using namespace std;
ll n;
int main(){
	ll i;
	cin>>n;
	if(n%2==1)
	{
		cout<<n/2<<endl;
	}
	else
	{
		for(i=31;i>=0;i--)
		{
			if(n&(1<<i))
			{
				cout<<(n-(1<<i))/2<<endl;
				break;
			}
		}
	}
	return 0;
}