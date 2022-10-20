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
ll n,s;
int main(){
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		cout<<s/((n/2)+1)<<endl;
	}
	return 0;
}