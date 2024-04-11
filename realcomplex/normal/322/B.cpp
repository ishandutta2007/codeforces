#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll r,g,b;
	cin >> r >> g >> b;
	ll ans = 0;
	for(ll j = 0;j<3;j++){
		if(j<=r&&j<=g&&j<=b){
			ll cur = j;
			cur += (r-j)/3;
			cur += (g-j)/3;
			cur += (b-j)/3;
			ans = max(ans,cur);
		}
	}
	cout << ans << endl;
	return 0;
}