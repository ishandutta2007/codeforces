#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll x;
	cin >> n >> x;
	ll s = 0;
	ll k;
	for(int j = 0;j<n;j++){
		cin >> k;
		s += k;
	}
	if(x-s==n-1)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}