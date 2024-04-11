#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	ll a, b;
	cin >> a >> b;
	
	for(ll i = (1ll << 62); i > 0; i >>= 1){
		ll x = i & a, y = i & b;
		if(x != y){
			printf("%lld\n", (i << 1) - 1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}