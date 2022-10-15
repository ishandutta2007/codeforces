#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n;
	cin>>n;
	vector< pair<ll,ll> > vec;
	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		vec.push_back({a,b});
	}
		n-=4;
		n/=2;
		cout<<n<<endl;
	
}