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
ll n,a,b;
int main(){
	ll T,i,p;
	cin>>T;
	while(T--)
	{
		cin>>n;
		p=1;
		a=b=0;
		for(i=0;i<10;i++)
		{
			if(i&1)
			{
				a+=(n%10)*p;
				p*=10;
			}
			else
			{
				b+=(n%10)*p;
			}
			n/=10;
		}
		cout<<(a+1)*(b+1)-2<<endl;
	}
	return 0;
}