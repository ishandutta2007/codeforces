#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	ll n,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n%2!=k%2||k*k>n)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}