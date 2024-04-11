#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll a,b,c,d;
	ll ans=0;
	cin>>a>>b>>c>>d;
	for(int x=a+b;x<=b+c;x++){
		if(x<c) continue;
		ans+=max(0LL,min(x-b,b)-max(x-c,a)+1)*(min(x-c,d-c+1));
	}
	cout<<ans<<'\n';
}