#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;

int main(){
	cin>>n>>k;
	ll ans=(n*8-1)/k+1+(n*5-1)/k+1+(n*2-1)/k+1;
	cout<<ans<<endl;
	return 0;
}