#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,k;
	cin >> n >> k;
	ll l = 1;
	int ans = 1;
	while((k+l)%(l*2)!=0){
		l*=2;
		ans++;
	}
	cout << ans;
	return 0;
}