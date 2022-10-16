#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_loop=32;
ll x, y, l, r, ans;
ll power(ll x, ll k){
	ll base=x, p=1;
	while(k){
		if(k&1) p*=base;
		base*=base;
		k>>=1;
	}
	return p;
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>l>>r;
	for(x=0; x<=max_loop; x++)
		for(y=0; y<=max_loop; y++){
			ll cur=power(2, x)*power(3, y);
			if(cur>r) break;
			if(cur>=l) ans++;
		}
	cout<<ans<<endl;
	return 0;
}